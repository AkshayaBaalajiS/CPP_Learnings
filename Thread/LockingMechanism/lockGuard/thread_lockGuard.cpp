#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <pthread.h>
using namespace std;

struct GStruct
{
	int a ;
	float b;
	char c;

	GStruct()
	{
		cout<<"@ GStruct constructor \n";
	}

	~GStruct()
	{
		cout<<"@ GStruct destructor \n";
	}
};	

GStruct * gstrObj = new GStruct();

mutex mutObj;


void * function(void * arg)
{
	cout<<"void * function(void * arg)\n";
	GStruct * ptr = static_cast<GStruct *>(arg);
	for(int i=0;i<20;i++)
	{
		auto start_time = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(2500));
		auto end_time = std::chrono::high_resolution_clock::now();
		auto tot_duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time);
		{
			lock_guard<mutex> localG(mutObj);
			ptr->a++;
		}
		cout<<"Iteration : " << i << " sleep for : " << tot_duration.count() <<endl;
	}
	cout<<"---------------------\n";
	return NULL;
}

void * function1(void * arg)
{
	cout<<"void * function1(void * arg)\n";
	static GStruct * ptr = static_cast<GStruct *>(arg);

	for(int i=0;i<20;i++)
	{
		auto start_time = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(900));
		auto end_time = std::chrono::high_resolution_clock::now();
		auto tot_duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time);
		{
			lock_guard<mutex> localG(mutObj);
			ptr->b++;
		} 
		cout<<"Iteration : " << i << " sleep for : " << tot_duration.count() <<endl;
	}
	cout<<"---------------------\n";
	return (void *)ptr;
}

int main()
{
	cout<<"pthread code to understand the threading in cpp\n";
	pthread_t thread1, thread2 ;
	pthread_create(&thread1, NULL, function, (void *)gstrObj);
	pthread_create(&thread2, NULL, function1, (void *)gstrObj);
	pthread_join(thread1, nullptr);
	void * ret ;
	pthread_join(thread2, &ret);
	cout<<"---------------------\n";
	cout<<"Final\n";
	cout<<"gstrObj->a = " << gstrObj->a <<endl;
	cout<<"gstrObj->b = " << gstrObj->b <<endl;
	GStruct * potrr = static_cast<GStruct *>(ret);
	cout<<"Final\n";
	cout<<"potrr->a = " << potrr->a <<endl;
	cout<<"potrr->b = " << potrr->b <<endl;
	cout<<"---------------------\n";
	
}