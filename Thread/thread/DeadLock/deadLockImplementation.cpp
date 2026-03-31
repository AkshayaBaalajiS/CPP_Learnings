#include <iostream>
#include <thread>
#include <chrono>
#include <condition_variable>

using namespace std;

bool ready1 = true;
bool ready2 = true;
condition_variable c1;

mutex m1;

void function1()
{
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now(); 
		unique_lock<std::mutex> ul(m1);
		c1.wait(ul, []{return ready1;});
		auto endTime = std::chrono::high_resolution_clock::now(); 
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"[DEBUG PRINT] function1 "<< i << " took " << duration.count() << "ms" <<endl;
		ready2 = false;
	}
}


void function2()
{
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now(); 
		unique_lock<std::mutex> ul(m1);
		c1.wait(ul, []{return ready2;});
		auto endTime = std::chrono::high_resolution_clock::now(); 
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"[DEBUG PRINT] function2 "<< i << " took " << duration.count() << "ms" <<endl;
		ready1 = false;
	}
}


int main()
{
	cout<<"This is the code to understand the deadLock and when it happens\n";
	thread t1(function1);
	thread t2(function2);
	// while(1)
	// {
	// 	c1.notify_all();
	// }
	t1.join();
	t2.join();
}