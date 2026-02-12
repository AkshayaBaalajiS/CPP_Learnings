#include <iostream>
#include <thread>
using namespace std;

void simpleFunction()
{
	cout<<"void simpleFunction()\n";
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(1234));
		auto endTime = std::chrono::high_resolution_clock::now();
		auto durationT = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"Duration taken for iteration :" << i << " = " << durationT.count() <<endl;
	}
}

int main()
{
	cout<<"Program to understand the cpp thread \n";

	thread t(simpleFunction);
	t.join();
}