#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>

using namespace std;
mutex m1;
bool check=false;
std::condition_variable c1;


void function()
{
	std::unique_lock<std::mutex> ul(m1);
	c1.wait(ul, [] {return check;} );
	cout<<"Now it get executed \n";
}

int main()
{
	cout<<"condition varaible in cpp \n";
	thread t1(function);

	{
		std::lock_guard<mutex> l1(m1);
		std::this_thread::sleep_for(std::chrono::milliseconds(1234));
		check = true;
	}
	t1.join();
}