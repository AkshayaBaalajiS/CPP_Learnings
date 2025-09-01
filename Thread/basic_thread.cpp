#include <iostream>
#include <thread>
#include <chrono>

using namespace std;


// int * function_1(void * arg)
// the thread function sig should be 
// void * function (void * )
void  * function_1(void * arg)
{
	int * pointer = static_cast<int *>(arg);
	cout << " @void function_1(void * arg) \n";
	for(int i=0;i<5;i++)
	{
		auto start_time  = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::seconds(2));
		auto end_time  = std::chrono::high_resolution_clock::now();
		auto duration_ = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time);
		cout<<"Duration for one iteration = " << duration_.count()<<endl;
		// *pointer++; // wrong 
		(*pointer)++;
	}
	return static_cast<void *>(pointer) ;
}

int main()
{
	cout<<"This is the program to ceck the thread how it works \n";

	pthread_t thread_1 ;

	// void * function_1(void * arg)
	// pthread_create(&thread_1, NULL, function_1, NULL ); // for void * this is the way 
	
	static int some_val=324;  
	int * some_pointer = &some_val;

	// now we will give diff type to the function    
	pthread_create(&thread_1, NULL, function_1, some_pointer);

	void  * return_1 ;
	pthread_join(thread_1, &return_1 );
	int * return_2 = static_cast <int *> (return_1);
	cout<< " The value returned from function = " << *return_2 <<endl;
}