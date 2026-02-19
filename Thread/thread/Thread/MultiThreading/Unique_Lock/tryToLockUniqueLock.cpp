#include <iostream>
#include <chrono>
#include <thread>
#include <future>
using namespace std;

int globlaVar = 234;

std::mutex m1 ;

void function1(std::promise<int> p)
{
	for(int i=0;i<10;i++)
	{
		auto startTime  = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(1234));
		std::unique_lock<mutex> lockM (m1, std::try_to_lock);
		if(lockM.owns_lock()) // same as try_to_lock and owns_lock mechanism 
		{
			cout<<"Function 1 Acquire lock\n";
			int someval = 23;
			globlaVar+=(someval+65);
		}
		else
		{
			cout<<"Lock not acquired on function1\n";
		}
		auto endTime  = std::chrono::high_resolution_clock::now();
		auto durationCast = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"total duration on function1 for " << i << " iteration  = " << durationCast.count() <<endl;
	}
	p.set_value(globlaVar);
}


void function2(std::promise<int> p)
{
	for(int i=0;i<10;i++)
	{
		std::unique_lock<mutex> lockM (m1, std::defer_lock);
		auto startTime  = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(1234));
		if(lockM.try_lock()) // same as try_to_lock and owns_lock mechanism 
		{
			cout<<"Function 2 Acquire lock\n";
			int someval = 23;
			globlaVar-=(someval-65);
		}
		else
		{
			cout<<"Lock not acquired on function2\n";
		}
		auto endTime  = std::chrono::high_resolution_clock::now();
		auto durationCast = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"total duration on function2 for " << i << " iteration  = " << durationCast.count() <<endl;
	}
	p.set_value(globlaVar);
}

int main()
{
	cout<<"defer lock in Unique_lock \n";
	int number = 23;
	std::promise <int> pr ;
	std::future <int> f = pr.get_future();

	std::promise <int> pr1 ;
	std::future <int> f1 = pr1.get_future();
	/*
	future.get() before the worker thread sets the promise value.

	future.get() blocks, so main() stops there and never reaches thread execution as you expect.
	if(f1.valid())
	{
		cout<< "Result from future 1  " << f1.get() <<endl;
	}
	*/
	thread t1(function1, std::move(pr));

	thread t2(function2, std::move(pr1));
	if(f1.valid())
	{
		cout<< "Result from future 1  " << f1.get() <<endl;
	}

	/*
	So what happens depends on timing:
		Case A: function2 finishes early

		If function2:

		completes all 10 iterations

		calls p.set_value(globlaVar)

		before main() reaches f1.get(),
	*/	

	t1.join();
	t2.join();
	// if(f1.valid())
	// {
	// 	cout<< "Result from future 1  " << f1.get() <<endl;
	// }
	if(f.valid())
	{
		cout<< "Result from future=  " << f.get() <<endl;
	}
}