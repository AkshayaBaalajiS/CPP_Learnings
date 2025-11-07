#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std;


int some_val[]={12,23,34,45,67,78,89,23,234,234,234};  
std::mutex mut;


void  * function_1(void * arg)
{
	int * pointer = static_cast<int *>(arg);
	cout << " @void function_1(void * arg) \n";
	mut.lock();
	for(int i=0;i<5;i++)
	{
		auto start_time  = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::seconds(1));
		auto end_time  = std::chrono::high_resolution_clock::now();
		auto duration_ = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time);
		cout<<"Duration for one iteration = " << duration_.count()<<endl;
		// *pointer++; // wrong 
		(*pointer)++;
	}
	mut.unlock();

	return static_cast<void *>(pointer) ;
}


void  * function_2(void * arg)
{
	int * pointer = static_cast<int *>(arg);
	cout << " @void function_2(void * arg) \n";
	mut.lock();
	for(int i=0;i<5;i++)
	{
		auto start_time  = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::seconds(2));
		auto end_time  = std::chrono::high_resolution_clock::now();
		auto duration_ = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time);
		cout<<"Duration for one iteration = " << duration_.count()<<endl;
		(*pointer)++;
		pointer++;
	}
	mut.unlock();
	return static_cast<void *>(pointer) ;
}

int main()
{
	cout<<"This is the program to ceck the thread how it works \n";

	pthread_t thread_1 ;
	pthread_t thread_2 ;

	int * some_pointer = some_val;
	int * some_pointer_1 = some_val;

	// now we will give diff type to the function    
	pthread_create(&thread_1, NULL, function_1, some_pointer);
	pthread_create(&thread_2, NULL, function_2, some_pointer_1);

	void  * return_1 ;
	void  * vreturn_2 ;
	pthread_join(thread_1, &return_1 );
	pthread_join(thread_2, &vreturn_2 );
	int * return_2 = static_cast <int *> (return_1);
	int * return_3 = static_cast <int *> (vreturn_2);
	cout<< " The value returned from function 1= " << *return_2 <<endl;
	cout<< " The value returned from function 2= " << *return_3 <<endl;

	int size_1 = sizeof(some_val)/ sizeof(some_val[0]);
	for(int i=0;i<size_1;i++)
	{
		cout<<some_val[i] << "   " ;
	}
	cout<<endl;
}