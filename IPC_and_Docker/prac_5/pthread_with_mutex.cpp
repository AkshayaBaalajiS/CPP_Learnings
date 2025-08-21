#include <iostream>
#include <mutex>
#include <chrono>
#include <thread>
using namespace std;

int number = 0;

std::mutex mutex_1 ;

void * thread_function_1(void * ref_1)
{
	// int * ref = static_cast<int *> (ref_1);
	for(int i=0;i<100;i++)
	{
		cout<<"This is from the thread_function_1 \n";
		auto start_time = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		auto end_time = std::chrono::high_resolution_clock::now();

		auto total_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time);
		cout<<"Total time for one iteration  : " << total_time.count() <<endl;

		// (*ref)++;
		mutex_1.lock();
		number++;
		mutex_1.unlock();
	}

}

/*
void * thread_function_2(void * ref_1)
{
	int * ref = static_cast<int *> (ref_1);
	for(int i=0;i<100;i++)
	{
		cout<<"This is from the thread_function_2 \n";
		auto start_time = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		auto end_time = std::chrono::high_resolution_clock::now();

		auto total_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time);
		cout<<"Total time for one iteration  : " << total_time.count() <<endl;

		(*ref)++;
	}

}
*/



int main()
{

	pthread_t thread_1;

	pthread_create(&thread_1, NULL, thread_function_1, NULL);

	pthread_t thread_2;

	pthread_create(&thread_2, NULL, thread_function_1, NULL);

	pthread_join(thread_1, NULL);

	cout<<"Total number = " << number ;


}