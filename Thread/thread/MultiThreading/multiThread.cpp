#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void * function(int & ref )
{
	 cout<<"void * function(int & ref )\n";
	 for(int i=0;i<10;i++)
	 {
	 	auto startTime = std::chrono::high_resolution_clock::now();
	 	std::this_thread::sleep_for(std::chrono::milliseconds(1234));
	 	auto endTime = std::chrono::high_resolution_clock::now();
	 	auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
	 	cout<<"Total Time on function "<<  i << " iteration ="  <<  dura.count() <<endl;
	 }
}
void * function1(int & ref )
{
	 cout<<"void * function1(int & ref )\n";
	 for(int i=0;i<10;i++)
	 {
	 	auto startTime = std::chrono::high_resolution_clock::now();
	 	std::this_thread::sleep_for(std::chrono::milliseconds(999));
	 	auto endTime = std::chrono::high_resolution_clock::now();
	 	auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
	 	cout<<"Total Time on function1 "<<  i << " iteration ="  <<  dura.count() <<endl;
	 }
}
int main()
{
	cout<<"Simple thread program \n";
	int number = 123;

	thread t1(function, std::ref(number));
	thread t2(function1, std::ref(number));
	t1.join();
	if(t2.joinable())
	{
		t2.join();
	}
}
// if no join ||||   std::terminate called 