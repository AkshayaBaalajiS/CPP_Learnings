#include <iostream>
#include <future>
#include <thread>
#include <functional>

using namespace std;

void function1(std::promise<int> p)
{
	int value = 234;
	std::this_thread::sleep_for(std::chrono::milliseconds(12345));
	p.set_value(value);
}

int main()
{
	cout<<"promise and future in cpp for taking value from thread function1 \n";
	std::promise<int> p ; //std::promise is non-copyable and must be transferred (moved) into the thread.
	std::future<int> f = p.get_future();
	// promise is not copyable so moved to thread 
	// thread t(function1, p);
	thread t(function1, std::move(p));
	int result ;
	if(f.valid())
	{
		result = f.get();  // future::get() BLOCKS until the promise sets the value.
	}
	cout<<"result from threadf before join = " << result <<endl;
	t.join();
	if(f.valid()) // once thre first get is done the valid will be false 
	{
		result = f.get();
	}
	cout<<"result from threadf after join = " << result <<endl;
}