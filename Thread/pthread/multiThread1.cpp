#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

struct A
{
	int a;
	char c;
	double d;
};

void * function1 (void * args)
{
	for(int i=0;i<10;i++)
	{
		cout<<"void * function1 (void * args)\n";
		A * ptr = static_cast<A *>(args);
		ptr->a = 123;
		ptr->c = 'a';
		ptr->d = 234.23423;
		auto start_time = std::chrono::high_resolution_clock::now();

		std::this_thread::sleep_for(static_cast<std::chrono::milliseconds>(1111));

		auto end_time = std::chrono::high_resolution_clock::now();

		auto tot_dur = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

		cout<<"Total duration = " << tot_dur.count() <<endl;
	}
}

void * function2 (void * args )
{
	static A * ptr = new A();

	for(int i=0;i<10;i++)
	{
		cout<<"void * function2 (void * args)\n";
		ptr->a =2342334;
		ptr->c = 'g';
		ptr->d = 234.678678678;
		auto start_time = std::chrono::high_resolution_clock::now();

		std::this_thread::sleep_for(static_cast<std::chrono::milliseconds>(2222));

		auto end_time = std::chrono::high_resolution_clock::now();

		auto tot_dur = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

		cout<<"Total duration = " << tot_dur.count() <<endl;
	}
	return ptr;
}

int main()
{
	pthread_t thread_1 , thread_2 ;
	A * ptr = new A();
	pthread_create(&thread_1, nullptr, function1, ptr );
	pthread_create(&thread_2, nullptr, function2, nullptr);
	pthread_join(thread_1, nullptr);
	cout<<"------thread1 ---------\n";
	cout<<"A = " << ptr->a <<endl;
	cout<<"B = " << ptr->c <<endl;
	cout<<"C = " << ptr->d <<endl;
	cout<<"--------------------------------\n";
	void * vptr = (void *) malloc(100 * sizeof(int));
	pthread_join(thread_2, &vptr);

	A * vptrr = static_cast<A *>(vptr);

	cout<<"-------Thread 2------\n";
	cout<<"A = " << vptrr->a <<endl;
	cout<<"B = " << vptrr->c <<endl;
	cout<<"C = " << vptrr->d <<endl;
	cout<<"--------------------------------\n";

}