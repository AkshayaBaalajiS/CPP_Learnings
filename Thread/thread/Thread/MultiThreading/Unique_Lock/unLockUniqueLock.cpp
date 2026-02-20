#include <iostream>
#include <future>
#include <thread>
#include <chrono>
using namespace std;

struct Structure
{
	int a ;
	int b;
	char * arr ;
};
Structure * ptr = new Structure();

std::mutex m1;

void * function1(std::promise<Structure *> ptr1)
{
	cout<<"@void * function1(std::promise<Structure *> ptr1)\n";
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(1234));
		auto endTime = std::chrono::high_resolution_clock::now();
		{
			std::unique_lock<mutex>llock (m1);
			ptr->a =234;
			ptr->b =674;
			ptr->arr ="Akshaya Baaalaji S";	
			// ptr1.set_value(ptr); // only once the set_value can be called 
			llock.unlock();
		}

		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"Total Duration of function1  = "<< dura.count() <<endl;		
	}
	ptr1.set_value(ptr);

}

int function2(std::promise<Structure> ptr1)
{
	cout<<"@int function2(std::promise<Structure *> ptr1)\n";
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(1204));
		auto endTime = std::chrono::high_resolution_clock::now();
		{	
			std::unique_lock<mutex>llock (m1);
			ptr->a =5;
			ptr->b =689;
			ptr->arr ="Baaalaji S";	
			// ptr1.set_value(*ptr); // only once the set_value can be called 
			llock.unlock();
		}
		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"Total Duration of function2  = "<< dura.count() <<endl;		
	}	
	ptr1.set_value(*ptr);

	return 0;
}

int main()
{
	cout<<"@ Multi threading in cpp nad usage of promise and future \n";
	std::promise<Structure> p;
	std::future<Structure> q = p.get_future();
	
	std::promise<Structure *> p1;
	std::future<Structure *> q1 = p1.get_future();
	
	thread t1(function1,std::move(p1));
	thread t2(function2,std::move(p));
	
	Structure obj;
	if(q.valid())
	{
		obj = q.get();
		cout<< " -- " << obj.a  << " -- " <<   obj.b << " -- " << obj.arr <<endl;

	}
	
	t1.join();
	t2.join();


	Structure * ptrr;
	if(q1.valid())
	{
		ptrr = q1.get();
		cout<< " -- " << ptrr->a  << " -- " <<   ptrr->b << " -- " << ptrr->arr <<endl;
	}
	
}