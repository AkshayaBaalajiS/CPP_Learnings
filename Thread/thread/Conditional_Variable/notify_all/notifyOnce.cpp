#include <iostream>
#include <thread>
#include <chrono>
#include <condition_variable>

using namespace std;

condition_variable c1;
bool pred = false;
mutex m1;

void function1()
{
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		unique_lock<mutex> ul(m1);
		c1.wait(ul, []{return pred;});
		pred = false;
		auto endTime = std::chrono::high_resolution_clock::now();
		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"[function1] "<< i <<" iteration = " << dura.count() <<endl;
	}
}

void function2()
{
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		unique_lock<mutex> ul(m1);
		c1.wait(ul, []{return pred;});
		pred = false;
		auto endTime = std::chrono::high_resolution_clock::now();
		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"[function2] "<< i <<" iteration = " << dura.count() <<endl;
	}
}

void function3()
{
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		unique_lock<mutex> ul(m1);
		c1.wait(ul, []{return pred;});
		pred = false;
		auto endTime = std::chrono::high_resolution_clock::now();
		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"[function3] "<< i <<" iteration = " << dura.count() <<endl;
	}
}

int main()
{
	cout<<"This is the code to understand the notify all \n";

	thread t1(function1);
	thread t2(function2);
	thread t3(function3);

	for(int i=0;i<10;i++)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1234));
		pred = true;
		c1.notify_one();
		cout<<"Notified the thread \n";
	}

	t1.join();
	t2.join();
	t3.join();
}