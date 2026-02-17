#include <iostream>
#include <chrono>
#include <thread>
#include <functional>

using namespace std;

int func(int & ref )
{
	int result =0;
	cout<<"int func(int & ref )\n";
	for(int i=0;i<10;i++)
	{
		auto startTime =  std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(1234));
		ref+=12;
		auto endTime =  std::chrono::high_resolution_clock::now();

		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime- startTime);
		cout<<"Duration taken for iteration :" << i+1 << " = " << dura.count() <<endl;
	}
	result = ref;
	return result;
}

int main()
{
	cout<<"This is the program to understand the thread how to get the return fro thread \n";
	int number = 12 ;
	thread t1(func, std::ref(number));
	int result=0;
	// t1.join(result); //join takes no arg 
	// result passing → std::future, std::promise, shared memory(global variable or shared mem we have to use )

}