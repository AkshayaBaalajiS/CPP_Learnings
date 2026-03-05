#include <iostream>
#include <thread>
#include <future>
#include <mutex>
#include <condition_variable>
using namespace std;

atomic<int> atom{1};

condition_variable c1;
condition_variable c2;

bool bool1 {false};
bool bool2 {false};

mutex m1 ;

void function1(std::promise<int> p, int &number1 )
{	
	int number;
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		std::unique_lock<std::mutex> ul(m1);
		c1.wait(ul, []{return bool1;});
		{
			cout<<"[function1] atom.load() = " << atom.load() <<endl;

			number = atom.load();
			number+=3;
			// p.set_value(number+number); // set_value can be called only once else exception raised 
			number1=number1+number;
		}
		// bool1 = false;
		auto endTime = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"[function1] " << i << " time = " << duration.count() <<endl;

		std::this_thread::sleep_for(std::chrono::milliseconds(1234));
		bool2 = true;
		// c2.notify_one();
		c2.notify_all();
		atom.store(number);
	}
	// atom.store(number);
	p.set_value(number+number);
}


void function2()
{	
	int number;
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		std::unique_lock<std::mutex> ul(m1);
		c1.wait(ul, []{return bool1;});
		{
			cout<<"[function2] atom.load() = " << atom.load() <<endl;

			number = atom.load();
			number+=3;

		}
		// bool1 = false;
		auto endTime = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"[function2] " << i << " time = " << duration.count() <<endl;

		std::this_thread::sleep_for(std::chrono::milliseconds(1234));
		bool2 = true;
		c2.notify_one();
		atom.store(number);
	}
	// atom.store(number);
}


void function3( )
{	
	int number;
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		std::unique_lock<std::mutex> ul(m1);
		c1.wait(ul, []{return bool1;});
		{
			cout<<"[function3] atom.load() = " << atom.load() <<endl;

			number = atom.load();
			number+=3;

		}
		bool1 = false;
		auto endTime = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"[function3] " << i << " time = " << duration.count() <<endl;

		std::this_thread::sleep_for(std::chrono::milliseconds(1234));
		bool2 = true;
		c2.notify_one();
		atom.store(number);
	}
	// atom.store(number);
}
int main()
{
	cout<<"This is the program to understand the atomic and the condition variable in cpp \n";
	cout<<"Atomic variable load  = " <<  atom.load()<<endl;

	std::promise<int> p1 ;
	std::future<int> f1 = p1.get_future();

	int number = 1;

	thread t1 (function1, std::move(p1), std::ref(number));
	thread t2 (function2);
	thread t3 (function3);
	
	for(int i=0;i<10;i++)
	{
		int number;
		std::this_thread::sleep_for(std::chrono::milliseconds(1987));
		bool1 = true;
		c1.notify_all();

		auto startTime = std::chrono::high_resolution_clock::now();
		std::unique_lock<std::mutex> ul(m1);
		c2.wait(ul, []{return bool2;});
		{
			cout<<"[main] atom.load() = " << atom.load() <<endl;
			number = atom.load();
			number-=2;
		}
		bool2 = false;
		auto endTime = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"[main] " << i << " time = " << duration.count() <<endl;

		atom.store(number);
	}

	t1.join();
	t2.join();
	t3.join();

	cout<<"Atomic variable = " <<  atom << endl;
	cout<<"Atomic variable load  = " <<  atom.load()<<endl;
	if(f1.valid())
	{
		cout<<"Q .get is : " << f1.get() <<endl;
	}
	cout<<"number = " << number <<endl;
}