#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

bool pred{false};
condition_variable cv;
mutex m1;

int function1(int & number)
{
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		unique_lock<std::mutex> ul(m1);
		cv.wait(ul, []{return pred;});
		pred = false;
		auto endTime = std::chrono::high_resolution_clock::now();
		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"[function1] " << i <<  " taken " << dura.count() << "ms" <<endl;
	}
	return 123; // std::thread ignores the return value of the function it runs.
}

int main()
{
	cout<<"This is the code to understand the return from the thread function \n";
	int number  = 123;

	thread t1(function1, std::ref(number));
	// std::thread ignores the return value of the function it runs.
	for(int i=0;i<10;i++)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1234));
		pred = true;
		cv.notify_one();
	}
	t1.join();
}