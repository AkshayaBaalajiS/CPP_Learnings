#include <iostream>
#include <chrono>
#include <condition_variable>
#include <mutex>

using namespace std;

mutex m1;

condition_variable c1;
condition_variable c2;

bool pred1{false};
bool pred2{false};

void function()
{
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		// std::this_thread::sleep_for(std::chrono::milliseconds(800));
		std::unique_lock<mutex> ul(m1);
		c1.wait(ul, []{return pred1;});
		pred1=false;
		auto endTime = std::chrono::high_resolution_clock::now();
		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"[Function] " << i << " iteration duration " << dura.count() <<endl;
		pred2=true;
		std::this_thread::sleep_for(std::chrono::milliseconds(1234));
		c2.notify_one();
	}

}

int main()
{
	cout<<"This is the condition variable implementation using 2 condition variable for sync the thread \n";
	thread t1(function);
	for(int i=0;i<10;i++)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1504));
		pred1=true;
		c1.notify_one();

		auto startTime = std::chrono::high_resolution_clock::now();
		// std::this_thread::sleep_for(std::chrono::milliseconds(1234));
		std::unique_lock<std::mutex>ul(m1);
		c2.wait(ul, []{return pred2;});
		pred2=false;
		auto endTime = std::chrono::high_resolution_clock::now();
		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"[main] " << i << " iteration duration " << dura.count() <<endl;

	}
	t1.join();
}