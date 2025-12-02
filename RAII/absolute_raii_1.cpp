#include <iostream>
#include <functional>
#include <pthread.h>
#include <thread>
#include <chrono>
using namespace std;


void * threadfunction (void * arg)
{
	cout<<"void * function (void * arg)\n";
	int * ptr =  static_cast<int *>(arg);
	for(int i=0;i<10;i++)
	{
		auto start_time = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(1750));
		auto end_time = std::chrono::high_resolution_clock::now();
		auto duraion_cast = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time);
		cout<<"Iteration : " <<  i << " took millisends : " << duraion_cast.count() <<endl;
		*ptr =  *ptr+2;
 	}
 	return nullptr;
}

class A
{
	pthread_t * thread_1 ;
	int variable;
	int * ptr ;
	public :
		A(std::function<void * (void *)> function_1) : variable(0), ptr(&variable)
		// A(std::functional<void *> arg)
		{
			//pthread expects ONLY this type:
			pthread_create(thread_1, nullptr, threadfunction, ptr );
			cout<<"@ A class Constructor \n";
		}
		~A()
		{
			pthread_join(*thread_1, nullptr);	
			cout<<"*ptr = " << *ptr<<endl;
			cout<<"@ A class destructor \n";
		}
		
};

int main()
{
	cout<<" This is the code to show the RAII example \n";

	std::function<void * (void *)> function_1 = threadfunction;
	A obj(threadfunction);
	std::function<void * (int)> lambda  = [](int a) 
	{
		return nullptr;
	};
}