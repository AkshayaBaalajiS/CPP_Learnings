#include <iostream>
#include <chrono>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex m1;
condition_variable c1;
condition_variable c2;
bool ready = false;
bool ready1 = false;

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
		cout<<"[function1] " << i << " iteration = " << duration.count() <<endl;
		ready1=true;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		c2.notify_one();
	}
}

int main()
{
	cout<<"condition variable in cpp \n";

	thread t1(function1);

	for(int i=0;i<10;i++)
	{
		std::unique_lock<mutex> ul(m1);
		cout<<"In main thread loop \n";
		ready = true;
		std::this_thread::sleep_for(std::chrono::milliseconds(1234));
		c1.notify_one();   // 🔔 THIS is what wakes function1

		auto startTime = std::chrono::high_resolution_clock::now();
	
		c2.wait(ul, [] {return ready1;});

		auto endTime = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"[main]  " << i << " iteration = " << duration.count() <<endl;
		ready1=false;
	}


	t1.join();

	cout<< "Global variable = " << globalData << endl;


}

// sync has been done with 2 condition variable making the one wait for other 
/*
main         					function1
make ready true              	thread awakes 
notify once         

wait on ready1                  sleeps for 1 sec and make ready1 true
dura 1 sec                      notify_one on c2  || awakes main thread c2 
awakes 
ready1 made to false 

*/