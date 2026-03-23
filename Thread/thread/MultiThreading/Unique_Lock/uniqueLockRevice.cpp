#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
// #include <unique_lock>
using namespace std;

mutex m1;
// mutex m3;
timed_mutex m2;

void func()
{
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		unique_lock<mutex> ul(m1, std::defer_lock);
		std::this_thread::sleep_for(std::chrono::milliseconds(1134));
		if(ul.try_lock())
		{
			cout<<"[func] lock acquired\n";
			auto endTime = std::chrono::high_resolution_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
			std::cout<<"[func] i =" << i << " ms = " << duration.count()<<endl; 
		}
		else
		{
			cout<<"[func] lock not acquired\n";
		}
		
	}
}

void func1()
{
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(1234));
		std::unique_lock<std::mutex>ul(m1);
		// unique_lock<mutex> ul(m1, std::defer_lock);
		// if(ul.try_lock())
		// {
		// 	cout<<"[func1] lock acquired\n";
		// }
		// else
		// {
		// 	cout<<"[func1] lock not acquired\n";
		// }
		cout<<"[func1] lock acquired\n";
		auto endTime = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		std::cout<<"[func1] i =" << i << " ms = " << duration.count()<<endl; 
	}
}

void func3()
{
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(1234));
		std::unique_lock<std::timed_mutex>ul(m2, std::chrono::milliseconds(1234));
		cout<<"[func3] lock acquired\n";
		auto endTime = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		std::cout<<"[func3] i =" << i << " ms = " << duration.count()<<endl; 
	}
}


int main()
{
	cout<<"This is the code to understand the unique lock in cpp \n";
	thread t1(func);	
	thread t2(func1);

	t1.join();
	t2.join();
}