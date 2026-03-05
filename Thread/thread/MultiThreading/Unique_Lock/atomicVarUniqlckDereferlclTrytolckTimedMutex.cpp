#include <iostream>
#include <future>
#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

struct A
{
	int a;
	int b ;
	char arr[100];
	A() :a(0), b(0)
	{

	}
	void operator+=(const int & ref)
	{
		a+=ref;
		b+=ref;
	}
	void operator-=(const int & ref)
	{
		a-=ref;
		b-=ref;
	}

	friend ostream & operator<< (ostream & out, A & ref)
	{
		out<<" Structure obj printed " <<  ref.a << " " << ref.b << " " << ref.arr <<endl;
		return out;
	}

	~A()
	{

	}
};
// } typedef Structure; // this can be done 

// typedef A Structure ; // this can also be done 
using  Structure = A ;

atomic<Structure* > atoStr = new Structure();

condition_variable cv;
condition_variable cv1;

atomic<bool> atoReady1{false};
atomic<bool> atoReady{false};



mutex m1;
timed_mutex m2;

void function1(std::promise<int> p)
{
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(1234));
		unique_lock<mutex> ul(m1);
		*atoStr+=2;
		auto endTime = std::chrono::high_resolution_clock::now();
		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"[function1] " << i << " iter " << dura.count() << " ms" << endl;
	}
	p.set_value(7);
}

void function2(int & num)
{
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(934));
		unique_lock<mutex> ul(m1, std::defer_lock);
		{
			ul.lock();
			*atoStr+=num;
			std::this_thread::sleep_for(std::chrono::milliseconds(1234)); // for makingthe function 3 locxk not acq 

			ul.unlock();
		}
		auto endTime = std::chrono::high_resolution_clock::now();
		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"[function2] " << i << " iter " << dura.count() << " ms" << endl;
	}
	num = 7;
}

void function3(atomic<int> & atovar)
{
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(1034));
		unique_lock<mutex> ul(m1, std::defer_lock);
		if(ul.try_lock())
		{
			*atoStr+=atovar.load();
			std::this_thread::sleep_for(std::chrono::milliseconds(1234)); // for makingthe function 4 locxk not acq 

		}
		else
		{
			cout<<"[function3] -- Lock not acquired \n";
		}
		auto endTime = std::chrono::high_resolution_clock::now();
		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"[function3] " << i << " iter " << dura.count() << " ms" << endl;
	}
	atovar.store(7);
}


void function4()
{
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(1134));
		unique_lock<mutex> ul(m1, std::try_to_lock);
		if(ul.owns_lock())
		{
			*atoStr-=6;
			std::this_thread::sleep_for(std::chrono::milliseconds(1234));
		}
		else
		{
			cout<<"[function4] -- Lock not acquired \n";
		}
		auto endTime = std::chrono::high_resolution_clock::now();
		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"[function4] " << i << " iter " << dura.count() << " ms" << endl;
	}
}

void function5()
{
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(1204));
		unique_lock<timed_mutex> ul(m2, std::chrono::milliseconds(12));
		if(ul.owns_lock())
		{
			*atoStr-=6;
			std::this_thread::sleep_for(std::chrono::milliseconds(2204));

		}
		else
		{
			cout<<"[function5] -- Lock not acquired \n";
		}
		auto endTime = std::chrono::high_resolution_clock::now();
		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"[function5] " << i << " iter " << dura.count() << " ms" << endl;
	}
}


void function6()
{
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(1234));
		unique_lock<timed_mutex> ul(m2, std::chrono::milliseconds(1932));
		if(ul.owns_lock())
		{
			*atoStr-=6;
		}
		else
		{
			cout<<"[function6] -- Lock not acquired \n";
		}
		auto endTime = std::chrono::high_resolution_clock::now();
		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"[function6] " << i << " iter " << dura.count() << " ms" << endl;
	}
}

void cvFunction()
{
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		unique_lock<mutex> ul(m1);
		cv.wait(ul, []{return atoReady.load();});
		// cv.wait(ul, []{return atoReady;});  // atomic variable cant be returned 
		*atoStr+=6;
		atoReady = false;
		auto endTime = std::chrono::high_resolution_clock::now();
		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"[cvFunction] " << i << " iter " << dura.count() << " ms" << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1934));
		atoReady1 = true;
		cv1.notify_one();
	}
}

int main()
{	
	std::promise<int> p;
	std::future<int> q = p.get_future();

	int number = 12;

	atomic<int> atovar{43};

	thread t1(function1, std::move(p));
	thread t2(function2, std::ref(number));
	thread t3(function3, std::ref(atovar));
	thread t4(function4);
	thread t5(function5);
	thread t6(function6);
	thread t7(cvFunction);
	for(int i=0;i<10;i++)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1634));
		atoReady = true;
		cv.notify_one();
		auto startTime = std::chrono::high_resolution_clock::now();
		unique_lock<mutex> ul(m1);
		cv1.wait(ul, []{return atoReady1.load();});
		// cv.wait(ul, []{return atoReady;});  // atomic variable cant be returned 
		*atoStr-=8;
		auto endTime = std::chrono::high_resolution_clock::now();
		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"[main] " << i << " iter " << dura.count() << " ms" << endl;
		atoReady1 = false;
	}
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	t7.join();
	if(q.valid())
	{
		cout<<"q hold " << q.get()<<endl;
	}
	cout<<"Number = " << number <<endl;
	cout<<*atoStr;
}