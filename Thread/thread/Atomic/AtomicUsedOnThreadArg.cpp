#include <iostream>
#include <thread>
#include <future>
#include <mutex>
#include <chrono>

using namespace std;

mutex m1;
timed_mutex m2 ;

template <typename T>
struct Structure
{
	public :
		int a ;
		int b ;
		char c;
		void operator +=(int && ref)
		{
			this->a+=ref;
			this->b+=ref;
			this->c+=1;
		}
		friend ostream & operator<<(ostream & out, Structure & ref)
		{
			out<<"Print the Structure " << ref.a << " " <<ref.b << " " <<ref.c ;
			return out;
		}
};
using IStruct = Structure<int>;

IStruct * gPtr = new IStruct();

void function1(std::promise<int> p )
{
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		auto endTime = std::chrono::high_resolution_clock::now();
		std::unique_lock<std::mutex>ul(m1);
		std::this_thread::sleep_for(std::chrono::milliseconds(1234));
		*gPtr+=2;
		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"[function1] " << i << " iteration took " << dura.count() <<endl;
	}
	p.set_value(12);
}

void function2(std::atomic<int> & p )
{
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		auto endTime = std::chrono::high_resolution_clock::now();
		std::unique_lock<std::mutex>ul(m1, std::defer_lock);
		if(ul.owns_lock())
		{
			*gPtr+=p;
			p-=1;
			std::this_thread::sleep_for(std::chrono::milliseconds(1134));
		}
		else
		{
			cout<<"-----------------[function2] lock not acquired---------------\n";
		}

		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"[function2] " << i << " iteration took " << dura.count() <<endl;
	}
}


void function3(int & ref)
{
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(444));
		auto endTime = std::chrono::high_resolution_clock::now();
		std::unique_lock<std::mutex>ul(m1, std::defer_lock);
		{
			ul.lock();
			*gPtr+=12;
			std::this_thread::sleep_for(std::chrono::milliseconds(1134));
			ul.unlock();
		}
		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"[function3] " << i << " iteration took " << dura.count() <<endl;
	}
}


void function4(std::atomic<int> & p )
{
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(666));
		auto endTime = std::chrono::high_resolution_clock::now();
		std::unique_lock<std::mutex>ul(m1, std::try_to_lock);
		if(ul.try_lock())
		{
			*gPtr+=p.load();
			p+=1;
			std::this_thread::sleep_for(std::chrono::milliseconds(1134));
		}
		else
		{
			cout<<"-----------------[function4] lock not acquired---------------\n";
		}

		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"[function4] " << i << " iteration took " << dura.count() <<endl;
	}
}

void function5(std::atomic<int> & p )
{
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(666));
		auto endTime = std::chrono::high_resolution_clock::now();
		std::unique_lock<std::timed_mutex>ul(m2, std::chrono::milliseconds(3220));
		if(ul.owns_lock())
		{
			*gPtr+=p.load();
			p+=1;
			std::this_thread::sleep_for(std::chrono::milliseconds(1134));
		}
		else
		{
			cout<<"-----------------[function5] lock not acquired---------------\n";
		}

		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"[function5] " << i << " iteration took " << dura.count() <<endl;
	}
}


void function6(std::atomic<int> & p )
{
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(900));
		auto endTime = std::chrono::high_resolution_clock::now();
		std::unique_lock<std::timed_mutex>ul(m2, std::chrono::milliseconds(10));
		if(ul.owns_lock())
		{
			*gPtr+=p.load();
			p+=1;
			std::this_thread::sleep_for(std::chrono::milliseconds(1134));
		}
		else
		{
			cout<<"-----------------[function6] lock not acquired---------------\n";
		}

		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"[function6] " << i << " iteration took " << dura.count() <<endl;
	}
}


int main()
{
	cout<<"Unique Lock Prac \n";

	std::atomic<int> ato {123};
	int number = 12;
	std::promise<int> p;
	std::future<int> f = p.get_future();

	thread t1(function1, std::move(p));
	thread t2(function3, std::ref(number));
	thread t3(function2, std::ref(ato));
	thread t4(function4, std::ref(ato));
	thread t5(function5, std::ref(ato));
	thread t6(function6, std::ref(ato));
	
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();


	if(f.valid())
	{
		cout<<"Future value = " << f.get() <<endl;
	}
	cout<<"ato = " << ato <<endl;
	cout<<"*ptr - " << *gPtr;

}