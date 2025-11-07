#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

void * function1(void * arg )
{
	int *arg1 = static_cast<int*>(arg);
	for(int i=0;i<15;i++)
	{
		auto start_time  = std::chrono::high_resolution_clock::now() ;

		std::this_thread::sleep_for(std::chrono::milliseconds(1123));

		auto end_time  = std::chrono::high_resolution_clock::now() ;
		auto time_diff = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time);
		(*arg1)++;
		cout<<"Time Diff for iteration " << i << " = " << time_diff.count()<<endl; 	
	}	

}

int main()
{
	cout<<"This is the program to understand the thread in C++\n";
	pthread_t thread1, thread2 ;

	static int a =234;
	int * ptr =&a;
	pthread_create(&thread1, NULL, function1, ptr );
	pthread_join(thread1, NULL);
}