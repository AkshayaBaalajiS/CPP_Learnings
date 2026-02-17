#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

struct Structure
{
	int a;
	int b;
	char c;
	Structure() : a(12), b(12), c('a')
	{

	}

	void operator+=(int a )
	{
		this->a+=a;
		this->b+=b;
		this->c+=c;
	}
};
Structure * str = new Structure();

mutex m1, m2;

void function(int number, char b)
{
	cout<<"void function()\n";
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(999));
		auto endTime = std::chrono::high_resolution_clock::now();
		{
			lock_guard<mutex> lockk(m1);
			str+=12;
		}
		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"Total Time on function "<<  i << " iteration ="  <<  dura.count() <<endl;
	}
}

void function1()
{
	cout<<"void function1()\n";
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(999));
		auto endTime = std::chrono::high_resolution_clock::now();
		{
			lock_guard<mutex> lockk(m2);
			str+=12;
		}
		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"Total Time on function1 "<<  i << " iteration ="  <<  dura.count() <<endl;
	}
}


int main()
{
	cout<<"Race Condition in cpp using thread\n";

	thread t1(function, 12, 'a');
	t1.join();


}