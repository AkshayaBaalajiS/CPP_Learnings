#include "header.hpp"
#include <thread>
#include <pthread.h>
#include <mutex>
#include <chrono>
using namespace std;

float globalVariable  = 234;

std::mutex mm;

void * function(void * ptr)
{
	static DataStructure * dptr = static_cast<DataStructure *>(ptr);
	cout<<"@void * function(void * ptr)\n";
	for(int i=0;i<10;i++)
	{	
		mm.lock();
		*dptr += globalVariable;
		globalVariable+= 1; // global varaible updated 
		mm.unlock();
		auto start_time = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(123));
		auto end_time = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
		cout<<"On function  total duration   = " << duration.count() << endl;
	}
	return dptr;

}

void * function1(void * ptr)
{
	static DataStructure * dptr = static_cast<DataStructure *>(ptr);
	cout<<"@void * function1(void * ptr)\n";
	for(int i=0;i<10;i++)
	{
		{
			std::lock_guard<mutex> lockG(mm);
			*dptr +=(globalVariable - 120);
			globalVariable+= .21; // global varaible updated 
		}

		auto start_time = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(111));
		auto end_time = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
		cout<<"On function1 total duration  = " << duration.count() << endl;
	}
	return dptr;

}

int main()
{
	cout<<"Program to understand the multi threading and mutex and lockguard usage \n";
	pthread_t thread_1 , thread_2;
	DataStructure * ptr = new DataStructure();
	DataStructure * ptr1 = new DataStructure();
	cout<<*ptr;

	pthread_create(&thread_1, nullptr, function, ptr );
	pthread_create(&thread_2, nullptr, function1, ptr1 );
	void * voidPtr  ;//= (void *)malloc(100 * sizeof(int));
	void * voidPtr1  ;//= (void *)malloc(100 * sizeof(int));
	pthread_join(thread_1, &voidPtr);
	pthread_join(thread_2, &voidPtr1);
	DataStructure * ptr11  = static_cast<DataStructure *>(voidPtr);
	DataStructure * ptr12  = static_cast<DataStructure *>(voidPtr1);

	cout<<"----------------------\n";
	cout<<*ptr; // arg checking 
	cout<<*ptr11; // return  checking
	cout<<"----------------------\n";
	cout<<"----------------------\n";
	cout<<*ptr1; // arg checking 
	cout<<*ptr12; // return  checking
	cout<<"----------------------\n";
	 
}