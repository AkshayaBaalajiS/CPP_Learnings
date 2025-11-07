#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

void thread_function_1(int & ref)
{
	for(int i=0;i<100;i++)
	{
		cout<<"This is from the thread_function_1 \n";
		auto start_time = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		auto end_time = std::chrono::high_resolution_clock::now();

		auto total_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time);
		cout<<"Total time for one iteration  : " << total_time.count() <<endl;

		ref++;
	}

}

int main()
{
	int number = 0;
	thread_function_1(number);

	cout<<"After function call the number is  : " << number<<endl;
}