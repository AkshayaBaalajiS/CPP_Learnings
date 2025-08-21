#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;


std::mutex mutex_1;

int Global_Counter;

void * function_1 (void * arg)
{
	for(int i=0;i<100;i++)
	{
		auto start_time = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(503));
		auto end_time = std::chrono::high_resolution_clock::now();
		
		// mutex_1.lock();
		std::lock_guard <std::mutex> lock_g_1 (mutex_1);
		Global_Counter++;

		// mutex_1.unlock();
		
		auto total = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time);

		cout<<"Time for iteration "<< i << " = " << total.count() << "ms\n";
	}
}

int main()
{
	cout<<"This is the program to make the thread run in the Docker\n";
	pthread_t thread_1;

	pthread_t thread_2;
	pthread_create(&thread_2, NULL, function_1, NULL);
	pthread_create(&thread_1, NULL, function_1, NULL);
	pthread_join(thread_1, NULL);
	pthread_join(thread_2, NULL);
	

	cout<<"Global Count = " << Global_Counter<<endl;
}