#include <iostream>
#include <future>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

mutex m1;

timed_mutex m2;


int glob =45;

// unique lock with simple mutex 
void function0(std::promise<int> p)
{
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(1004));

		std::unique_lock<mutex> ul (m1);
		{
			glob+=32;
			ul.unlock();
		}

		auto endTime = std::chrono::high_resolution_clock::now();
		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"Duration for " <<  i << " iteration on function = " << dura.count() <<endl;
	}
	p.set_value(glob);
}


//unique lock with defer lock 
void function1(std::promise<int> p)
{
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(1034));

		std::unique_lock<mutex> ul (m1, std::defer_lock);
		{
			ul.lock();
			glob-=2;
			std::this_thread::sleep_for(std::chrono::milliseconds(1500)); // sleep for lock not getting on function2 and funftion3 
			ul.unlock();
		}

		auto endTime = std::chrono::high_resolution_clock::now();
		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"Duration for " <<  i << " iteration on function1 = " << dura.count() <<endl;
	}
	p.set_value(glob);

}


//unique lock with defer lock and owns lock used 
void function2(float * arr)
{
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(1034));

		std::unique_lock<mutex> ul (m1, std::defer_lock);
		if(ul.try_lock())
		{
			glob+=32;
		}
		else
		{
			cout<<"Lock not acquired on function 2 \n";
		}

		auto endTime = std::chrono::high_resolution_clock::now();
		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"Duration for " <<  i << " iteration on function2 = " << dura.count() <<endl;
	}
	arr[0] = glob;
}

//unique lock with try_to_lock
void function3(int & number)
{
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(1004));

		std::unique_lock<mutex> ul (m1, std::try_to_lock);
		if(ul.owns_lock())
		{
			glob-=3;
		}
		else
		{
			cout<<"Lock not acquired on function3 \n";
		}

		auto endTime = std::chrono::high_resolution_clock::now();
		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"Duration for " <<  i << " iteration on function3 = " << dura.count() <<endl;
	}
	number = glob;
}

//unique lock with timed_mutex and timer 
void function4(int & number)
{
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(1030));

		std::unique_lock<timed_mutex> ul (m2, std::chrono::milliseconds(20));
		if(ul.owns_lock())
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(1030)); // for making the lock not acq on thread 5 // function5 
			glob/=32;
		}
		else
		{
			cout<<"Lock not acquired on function4 \n"; 
		}

		auto endTime = std::chrono::high_resolution_clock::now();
		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"Duration for " <<  i << " iteration on function4 = " << dura.count() <<endl;
	}
	number=glob;
}

//unique lock with timed_mutex and timer 
void function5(int & number)
{
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(1030));

		std::unique_lock<timed_mutex> ul (m2, std::chrono::milliseconds(1));
		if(ul.owns_lock())
		{
			glob/=32; 
			std::this_thread::sleep_for(std::chrono::milliseconds(1030)); // for making the lock not acquired on function 4 // thread 4 
		}
		else
		{
			cout<<"Lock not acquired on function5 \n";
		}

		auto endTime = std::chrono::high_resolution_clock::now();
		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"Duration for " <<  i << " iteration on function5 = " << dura.count() <<endl;
	}
	number=glob;
}


int main()
{
	int number = 32;
	float arr[] = {12,23,34,45,56};

	std::promise<int> p ;
	std::future<int> q1 = p.get_future();

	std::promise<int> p1 ;
	std::future<int> q2 = p1.get_future();

	thread t1(function0, std::move(p));
	thread t2(function1, std::move(p1));
	thread t3(function2, arr);
	thread t4(function3, std::ref(number));
	thread t5(function4, std::ref(number));
	thread t6(function5, std::ref(number));
	
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	if(q2.valid())
	{
		cout<<"Thread 2 value returned is" <<  q2.get() <<endl;
	}	
	if(q1.valid())
	{
		cout<<"Thread 1 value returned is" <<  q1.get() <<endl;
	}	

	cout<<"Thread 3 returned / updated variable = " << arr[0] << endl;
	cout<<"Thread 4 returned / updated number variable = " << number << endl;
	cout<<"Thread 5 returned / number  variable = " << number << endl;
	
}
