#include <thread>
#include <iostream>
#include <pthread.h>
#include <chrono>
using namespace std;


struct A
{
	int a;
	char b;
	double d;
	string s;
};

void * function (void * args)
{
	for(int i=0;i<10;i++)
	{	
		cout<<"@void * function (void * args)\n";
		auto start_time = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(1233));
		auto end_time = std::chrono::high_resolution_clock::now();
		auto duration_taken = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time);
		cout<<"Duration taken  = " << duration_taken.count()<<endl; 
	}
}


void * function1 (void * args)
{
	static A * ptr =  new A();
	for(int i=0;i<10;i++)
	{	
		cout<<"@void * function (void * args)\n";
		auto start_time = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(122));
		auto end_time = std::chrono::high_resolution_clock::now();
		auto duration_taken = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time);
		ptr->a = 21;
		ptr->b = 'g';
		ptr->s = "Baalaji S";
		ptr->d = 4.23423;
		cout<<"Duration taken  = " << duration_taken.count()<<endl; 
	}
	return ptr;
}

int main()
{
	cout<<"@ Thread program in cpp \n";
	A * ptr = new A();
	ptr->a = 234;
	ptr->b = 'a';
	ptr->s = "Akshaya Baalaji S";
	ptr->d = 234.23423;
	
	pthread_t thread_id, thread_id1 ;

	pthread_create(&thread_id, NULL, function, NULL );
	pthread_create(&thread_id1, NULL, function1, static_cast<void *>(ptr) );
	
	pthread_join(thread_id, NULL);

	void ** orgPtr = (void **)malloc(76*sizeof(int));
	pthread_join(thread_id1, orgPtr);
	// void  * aptr = static_cast<void *>(orgPtr);
	A *aaptr = static_cast<A *>(*orgPtr);
	// A * aptr = static_cast<A *>(*orgPtr);
	cout<<"a = " << aaptr->a <<endl;
	cout<<"b = " << aaptr->b <<endl;
	cout<<"s = " << aaptr->s <<endl;
	cout<<"d = " << aaptr->d <<endl;

	// void * orgPtr;
	// pthread_join(thread_id1, &orgPtr);
	// A  * aptr = static_cast<A *>(orgPtr);
	// cout<<"A = " << aptr->a <<endl;
	// cout<<"b = " << aptr->b <<endl;
	// cout<<"s = " << aptr->s <<endl;
	// cout<<"d = " << aptr->d <<endl;

}