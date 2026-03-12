#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
using namespace std;

mutex m1;
mutex mainMutex;
mutex m2;
mutex m3;
condition_variable cv;
condition_variable cvmain;
bool pred1 =false;
bool pred2 =false;
bool pred3 =false;
bool mainPred =false;

void function1()
{
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		unique_lock<std::mutex> ul(m1);
		cv.wait(ul, []{return pred1;});
		pred1 = false;
		auto endTime = std::chrono::high_resolution_clock::now();
		auto durationCast = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"[function1] Duration = " << durationCast.count() << endl;
		mainPred = true;
		std::this_thread::sleep_for(std::chrono::milliseconds(1534));

		cvmain.notify_one();
	}
}
void function2()
{
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		unique_lock<std::mutex> ul(m2);
		cv.wait(ul, []{return pred2;});
		pred2 = false;
		auto endTime = std::chrono::high_resolution_clock::now();
		auto durationCast = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"[function2] Duration = " << durationCast.count() << endl;
		mainPred = true;
		std::this_thread::sleep_for(std::chrono::milliseconds(1534));

		cvmain.notify_one();
	}
}
void function3()
{
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		unique_lock<std::mutex> ul(m3);
		cv.wait(ul, []{return pred3;});
		pred3 = false;
		auto endTime = std::chrono::high_resolution_clock::now();
		auto durationCast = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"[function3] Duration = " << durationCast.count() << endl;
		mainPred = true;
		std::this_thread::sleep_for(std::chrono::milliseconds(1534));

		cvmain.notify_one();
	}
}

int main()
{
	cout<<"This is the program to understand the condition variable to notifyAll\n";
	thread t1(function1);
	thread t2(function2);
	thread t3(function3);
	for(int i=0;i<10;i++)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1234));
		pred1 = true;
		pred2 = true;
		pred3 = true;
		cv.notify_all();
		
		auto startTime = std::chrono::high_resolution_clock::now();
		unique_lock<std::mutex> ul(mainMutex);
		cvmain.wait(ul, []{return mainPred;});
		mainPred = false;

		auto endTime = std::chrono::high_resolution_clock::now();
		auto durationCast = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"[MAIN] Duration = " << durationCast.count() << endl;

	}
	t1.join();
	t2.join();
	t3.join();

}