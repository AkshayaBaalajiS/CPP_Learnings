#include <iostream>
#include <chrono>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex m1;
condition_variable c1;
bool ready = false;

int globalData=12;

void function1()
{
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		cout<<"@ function1 before lock\n";
		std::unique_lock<std::mutex> ul (m1); // 
		
		c1.wait(ul, [] {return ready;}); // c1.wait() requires the mutex to be locked
		cout<<"@ function1 after lock\n";
		globalData+=2;
	
		ready=false;
		auto endTime = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"Duration on function1 for " << i << " iteration = " << duration.count() <<endl;
	}
}

int main()
{
	cout<<"condition variable in cpp \n";

	thread t1(function1);

	for(int i=0;i<10;i++)
	{
		{
			std::lock_guard<mutex> l1(m1);
			cout<<"In main thread loop \n";
			ready = true;
			c1.notify_one();   // 🔔 THIS is what wakes function1
			std::this_thread::sleep_for(std::chrono::milliseconds(1234));
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1234));

	}


	t1.join();

	cout<< "Global variable = " << globalData << endl;


}