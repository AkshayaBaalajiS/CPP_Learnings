#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

atomic<float> ato {123.345};

mutex m1;

void function1()
{
	for(int i=0;i<10;i++)
	{
		auto startTime =  std::chrono::high_resolution_clock::now();
		auto endTime =  std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(785));
		unique_lock<mutex> ul(m1, std::defer_lock);
		if(ul.try_lock())
		{
			cout<<"[function1] Lock Acquried\n";
			int a = ato.load();
			a++;
		}
		else
		{
			cout<<"[function1] Lock Not Acquired \n";
		}

		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"[function1]  Total time  " << dura.count() <<endl;
	}
}

void function2()
{
	for(int i=0;i<10;i++)
	{
		auto startTime =  std::chrono::high_resolution_clock::now();
		auto endTime =  std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(785));
		unique_lock<mutex> ul(m1, std::defer_lock);
		if(ul.try_lock())
		{
			cout<<"[function2] Lock Acquried\n";
			std::this_thread::sleep_for(std::chrono::milliseconds(1234));

			int a = ato.load();
			a++;
		}
		else
		{
			cout<<"[function2] Lock Not Acquired \n";
		}

		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"[function2]  Total time  " << dura.count() <<endl;
	}
}

int main()
{
	cout<<"THis is the program to understand the try lock in cpp in unique_lock \n";
	thread t1(function1);
	thread t2(function2);
	t2.join();
	t1.join();
}