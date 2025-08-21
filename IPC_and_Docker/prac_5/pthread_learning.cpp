#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

void * thread_function_1(void * ref_1)
{
	int * ref = static_cast<int *> (ref_1);
	for(int i=0;i<100;i++)
	{
		cout<<"This is from the thread_function_1 \n";
		auto start_time = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		auto end_time = std::chrono::high_resolution_clock::now();

		auto total_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time);
		cout<<"Total time for one iteration  : " << total_time.count() <<endl;

		(*ref)++;
	}

}

int main()
{
	int number = 0;
	pthread_t thread_1; // unique identifier for thread 

	pthread_create(&thread_1, NULL, thread_function_1, &number );
	cout<<"After function call the number is  : " << number<<endl;
	
	// WHy the pthread_join is necessary ? Below is the answer 
	//If main() finishes before thread_function_1 completes, the process exits, which kills all threads, even if they are still running.

	pthread_join(thread_1, NULL);
}