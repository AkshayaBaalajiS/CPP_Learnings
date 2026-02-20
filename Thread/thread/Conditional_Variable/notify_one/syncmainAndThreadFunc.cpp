#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <future>
#include <condition_variable>

using namespace std;

int globalVariable = 12;

mutex m1;
condition_variable c1;
condition_variable c2;
bool ready = false;
bool ready1 = false;

void function1(std::promise<int>  ref)
{
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		std::unique_lock<mutex>ul(m1);
		c1.wait(ul, []{return ready;});
		globalVariable+=23;
		auto endTime = std::chrono::high_resolution_clock::now();
		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"[function] " << i << " took " << dura.count() << " ms \n";
		ready = false;
		ready1 = true;
		std::this_thread::sleep_for(std::chrono::milliseconds(1234));
		c2.notify_one();
	}
	ref.set_value(globalVariable);
}

int main()
{
	int number =123;
	std::promise<int> p ;
	std::future<int> q = p.get_future();
	thread t1(function1, std::move(p));
	for(int i=0;i<10;i++)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1523));
		ready = true ;
		c1.notify_one();
		auto startTime = std::chrono::high_resolution_clock::now();
		std::unique_lock<mutex>ul(m1);
		c2.wait(ul, []{return ready1;});
		globalVariable*=.3;
		ready1 = false;
		auto endTime = std::chrono::high_resolution_clock::now();
		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"[main] " << i << " took " << dura.count() << " ms \n";

	}
	if(q.valid())
	{
		cout<<"q from the thread function returned " << q.get() <<endl;
	}
	cout<<"globalVariable = " << globalVariable <<endl;	
}