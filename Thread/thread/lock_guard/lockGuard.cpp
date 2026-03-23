#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
mutex m1;

void function1()
{
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(1234));
		{
			lock_guard<mutex>lg(m1);
			auto endTime = std::chrono::high_resolution_clock::now();
			auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
			cout<<"[function1] i = " << i << " ms = " << dura.count() <<std::endl; 
		}
	}
}


void function2()
{
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(1134));
		{
			lock_guard<mutex>lg(m1);
			auto endTime = std::chrono::high_resolution_clock::now();
			auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
			cout<<"[function2] i = " << i << " ms = " << dura.count() <<std::endl; 
		}
	}
}


int main()
{
	cout<<"This is the program to understand the lock_guard in cpp\n";
	thread t1(function1);
	thread t2(function2);

	t1.join();
	t2.join();
}