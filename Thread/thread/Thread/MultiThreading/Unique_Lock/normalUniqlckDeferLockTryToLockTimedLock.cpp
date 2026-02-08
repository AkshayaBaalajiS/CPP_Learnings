#include <iostream>
#include <future>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

int globalVar =23;

mutex m1;
timed_mutex tm1;

void function1(std::promise<int> p)
{
	for(int i=0;i<10;i++)
	{	
		auto startTime = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(2323));
		{
			unique_lock<mutex> ul(m1);
			globalVar-=12;
		}
		auto endTime = std::chrono::high_resolution_clock::now();
		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"[Function1] Wait time = " << dura.count() <<endl;
	}
	p.set_value(globalVar);
}

void function2(std::promise<int> p)
{
	for(int i=0;i<10;i++)
	{	
		auto startTime = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(1323));
		unique_lock<mutex> ul(m1, std::defer_lock);
		ul.lock();
			globalVar/=12;
			std::this_thread::sleep_for(std::chrono::milliseconds(1313));
		ul.unlock();
		auto endTime = std::chrono::high_resolution_clock::now();
		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"[Function2] Wait time = " << dura.count() <<endl;
	}
	p.set_value(globalVar);
}

void function3(int & num)
{
	for(int i=0;i<10;i++)
	{	
		auto startTime = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(1323));
		unique_lock<mutex> ul(m1, std::defer_lock);
		if(ul.try_lock())
		{
			globalVar+=12;
		}
		else
		{
			cout<<"Not Acquired lock on function3\n";
		}
		auto endTime = std::chrono::high_resolution_clock::now();
		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"[Function3] Wait time = " << dura.count() <<endl;
	}
	num = globalVar;

}

void function4(int & num)
{
	for(int i=0;i<10;i++)
	{	
		auto startTime = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(1723)); // sleep is not enough cause other thread still hold the mutex (locked) so make more sleep
		// std::this_thread::sleep_for(std::chrono::milliseconds(2923));
		unique_lock<mutex> ul(m1, std::try_to_lock);
		if(ul.owns_lock())
		{
			globalVar*=12;
		}
		else
		{
			cout<<"Not Acquired lock on function4\n";
		}
		auto endTime = std::chrono::high_resolution_clock::now();
		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"[Function4] Wait time = " << dura.count() <<endl;
	}
	num = globalVar;

}


void function5(int & num)
{
	for(int i=0;i<10;i++)
	{	
		auto startTime = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(1723));
		unique_lock<timed_mutex> ul(tm1, std::chrono::milliseconds(1212));
		if(ul.owns_lock())
		{
			globalVar+=12;
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));

		}
		else
		{
			cout<<"Not Acquired lock on function5\n";
		}
		auto endTime = std::chrono::high_resolution_clock::now();
		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"[Function5] Wait time = " << dura.count() <<endl;
	}
	num = globalVar;

}

void function6(int & num)
{
	for(int i=0;i<10;i++)
	{	
		auto startTime = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(1723));
		unique_lock<timed_mutex> ul(tm1, std::chrono::milliseconds(12));
		if(ul.owns_lock())
		{
			globalVar+=12;
		}
		else
		{
			cout<<"Not Acquired lock on function6\n";
		}
		auto endTime = std::chrono::high_resolution_clock::now();
		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"[Function6] Wait time = " << dura.count() <<endl;
	}
	num = globalVar;
}
int main()
{
	int number =12;
	promise<int> p;
	future<int> f = p.get_future();

	
	promise<int> p1;
	future<int> f1 = p1.get_future();
	

	thread t1(function1, std::move(p));
	thread t2(function2, std::move(p1));
	thread t3(function3, std::ref(number));
	thread t4(function4, std::ref(number));
	thread t5(function5, std::ref(number));
	thread t6(function6, std::ref(number));

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();

	if(f.valid())
	{
		cout<<"The function1 return " << f.get() <<endl;
	}

	if(f1.valid())
	{
		cout<<"The function2 return " << f1.get() <<endl;
	}
	cout<<"Number = " << number<<endl;
	
	
}