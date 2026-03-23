#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex m1;
timed_mutex tm1;
condition_variable c1;

bool ready1 = false;

void function1()
{
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		unique_lock<std::mutex> ul(m1);
		c1.wait(ul, []{return ready1;});
		auto endTime = std::chrono::high_resolution_clock::now();
		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"[function1] i = " << i << " ms = " << dura.count() <<std::endl; 
		ready1 = false;
	}
}


int main()
{
	cout<<"This is the code to understand the condition variable in cpp\n";
	thread t1(function1);
	for(int i=0;i<10;i++)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1234));
		ready1 = true;
		c1.notify_one();
	}
	t1.join();
}