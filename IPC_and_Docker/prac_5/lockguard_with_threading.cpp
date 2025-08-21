#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

int counter ;

std::mutex mutex_1;


void * print_function_1(void * ref)
{
	for(int i=0;i<100;i++)
	{
		auto start_time = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(514));
		std::this_thread::sleep_for(std::chrono::seconds(1));
		auto end_time = std::chrono::high_resolution_clock::now();

		auto total = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time);
		cout<<"Iteration time  = " << total.count()<<endl;
		
		// commenting mutex for using lock gaurd 
		std::lock_guard<std::mutex> lock_mutex(mutex_1);
		// mutex_1.lock();
		counter++;
		// mutex_1.unlock();
	}
}


int main()
{
	pthread_t thread_1, thread_2;

	pthread_create(&thread_1, NULL, print_function_1, NULL);

	pthread_create(&thread_2, NULL, print_function_1, NULL);

	pthread_join(thread_1, NULL);
	pthread_join(thread_2, NULL);

	cout<<"At end counter =  "<<counter<<endl;
}
