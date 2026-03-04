#include <iostream>
#include <thread>
#include <chrono>
#include <functional>

using namespace std;

void function1(int & arg )
{
	cout<<"void function1(int arg )\n";
	for(int i=0;i<10;i++)
	{
		auto startTime =  std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(1234));
		arg+=12;
		auto endTime =  std::chrono::high_resolution_clock::now();

		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime- startTime);
		cout<<"Duration taken for iteration :" << i+1 << " = " << dura.count() <<endl;
	}
}

void func(int & reff)
{
	cout<<"before reff = " <<  reff <<endl;
	reff+=12;
	cout<<"before reff = " <<  reff <<endl;
	
}

int main()
{
	cout<<"Thread with arg passed as arg \n";
	int number = 0;
	func(number);
	cout<<"number before thread = " << number <<endl;
	thread t(function1, std::ref(number) ); // herer in thread it just copies the value 
	t.join();
	cout<<"number after thread = " << number <<endl;
}