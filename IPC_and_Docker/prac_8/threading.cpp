#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void * thread_function(void * arg)
{
	for(int i=0;i<100;i++)
	{
		auto start_time = std::chrono::high_resolution_clock::now();

		std::this_thread::sleep_for(std::chrono::milliseconds(502));
		std::this_thread::sleep_for(std::chrono::milliseconds(2));

		auto end_time = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time);
		cout<<"Time taken for " << i << " iteration  = " << duration.count()<<endl;
	}

	return NULL;
}

int main()
{
	cout<<"This is the threading program \n";
	pthread_t thread_1, thread_2;

	pthread_create(&thread_1, NULL, thread_function, NULL);
	pthread_create(&thread_2, NULL, thread_function, NULL);

	pthread_join(thread_1, NULL);
	pthread_join(thread_2, NULL);

}