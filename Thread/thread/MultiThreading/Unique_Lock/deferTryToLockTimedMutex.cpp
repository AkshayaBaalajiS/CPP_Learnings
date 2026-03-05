#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <future>

using namespace std;

int globalData = 12;
std::mutex m1;
std::timed_mutex m2;

void function1(promise<int> p)
{
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(1200));
		{
			std::unique_lock<std::mutex> ul (m1);
			// ul.lock(); // already locked 
			globalData+=2;
			ul.unlock(); // only unlock can be dopne manually 
		}
		auto endTime = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"Duration on function1 for " << i << " iteration = " << duration.count() <<endl;
	}
	p.set_value(globalData);
}


void function2(promise<int> p)
{
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(1230));
		std::unique_lock<std::mutex> ul (m1, std::defer_lock);
		{
			ul.lock();
			globalData*=2;
			ul.unlock();
		}
		auto endTime = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"Duration on function2 for " << i << " iteration = " << duration.count() <<endl;
		
	}
	p.set_value(globalData);
}

void function3(int & number)
{
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(1204));
		std::unique_lock<std::mutex> ul (m1, std::try_to_lock);
		if(ul.owns_lock())
		{
			globalData-=2;
		}
		else
		{
			cout<<"On function 3 the lock not acquired\n";
		}
		auto endTime = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"Duration on function3 for " << i << " iteration = " << duration.count() <<endl;
		
	}
	number= globalData;
}

void function4(int & number)
{
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(1034));
		std::unique_lock<std::timed_mutex> ul (m2, std::chrono::milliseconds(500));
		if(ul.owns_lock())
		{
			globalData/=2;
		}
		else
		{
			cout<<"On function 4 the lock not acquired\n";
		}
		auto endTime = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"Duration on function4 for " << i << " iteration = " << duration.count() <<endl;
		
	}
	number= globalData;

}

void function5(int & ref)
{
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(1004));
		std::unique_lock<std::mutex> ul (m1, std::defer_lock);
		if(ul.try_lock())
		{
			globalData*=12;
		}else
		{
			cout<<"On function 5 the lock not acquired\n";
		}
		auto endTime = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"Duration on function5 for " << i << " iteration = " << duration.count() <<endl;
		
	}
	ref= globalData;
}



int main()
{
	cout<<"defer lock, timed lock, try to lock of unique_lock in cpp\n";


	int num =1;
	std::promise<int> p;
	std::future<int> q = p.get_future();

	std::promise<int> p1;
	std::future<int> q1 = p1.get_future();
	
	thread t1(function1, std::move(p));

	thread t2(function2, std::move(p1));

	thread t3(function3, std::ref(num));

	thread t4(function4, std::ref(num));

	thread t5(function5, std::ref(num));
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();


	
	if(q.valid())
	{
		cout<<"value from the thread 1  = " << q.get() <<endl;
	}

	if(q1.valid())
	{
		cout<<"value from the thread 1  = " << q1.get() <<endl;
	}
	cout<<"updated number = " << num <<endl;
	

}