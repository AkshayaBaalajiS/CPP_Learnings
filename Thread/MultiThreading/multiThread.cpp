#include <iostream>
#include <thread>
#include <cstring>
#include <chrono>
using namespace std;


void * function1(void * args)
{
	static int some_var = 234;

	cout<<"void * function1(void * args)\n";
	for(int i=0;i<20;i++)
	{
		cout<<"----------------------------------------------------\n";
		auto start_time = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::seconds(3));
		auto end_time =  std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);
		cout<<"Time taken for " << i << "  iteration is " <<  duration.count() <<std::endl;
		cout<<"----------------------------------------------------\n";

	}
	return static_cast<void *>(&some_var);
}

void * function2(void * args)
{
	cout<<"void * function2(void * args)\n";
	for(int i=0;i<20;i++)
	{
		cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++\n";

		auto start_time = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(1500));
		auto end_time =  std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
		cout<<"Time taken for " << i << "  iteration is " <<  duration.count() << "  value =  " <<*(static_cast<int *>(args)) <<std::endl;
		cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++\n";
	
	}

}



int main()
{
	pthread_t thread1;
	pthread_t thread2;

	static int a =234;

	void** voidPtr;

	pthread_create(&thread1, NULL, function1, NULL);
	pthread_create(&thread2, NULL, function2, &a);

	pthread_join(thread1, voidPtr);
	int * result_ptr = static_cast<int *>(*voidPtr);
	cout<<"Value returned from the result pointer = " << *result_ptr <<endl;
	pthread_join(thread2, NULL);

}