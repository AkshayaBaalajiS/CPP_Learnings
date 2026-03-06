#include <iostream>
#include <thread>
#include <functional>
#include <chrono>

using namespace std;
/*
Thread 1 locks m1

Thread 2 locks m2

Both threads can enter the critical section at the same time
*/
struct Structure
{
	int * a ;
	float * b ;
	int size ;
	Structure(int size, int * a=nullptr , float *b=nullptr) : size(size)
	{
		a = new int[size];
		b = new float[size];
	}

	Structure(const Structure & ref) : size(ref.size)
	{
		a = new int[size];
		b = new float[size];
		for(int i=0;i<size;i++)
		{
			a[i] = ref.a[i];
			b[i] = ref.b[i];
		}
	}

	Structure(Structure && ref ) : size(ref.size)
	{
		// if(this!=&ref) // only on move assignment we hvae to do this 
		// {
			a = ref.a;
			b= ref.b;
			ref.a = nullptr;
			ref.b = nullptr;	
			ref.size = 0;		
		// }
	}

	friend ostream & operator << (ostream & out, Structure & st)
	{
		for(int i=0;i<st.size;i++)
		{
			out<< st.a[i] << "-----" << st.b[i] <<endl;
		}
		return out;
	}

	void operator+=(const int & ref )  // cpp looks for operator+=(Structure* , int) be carefule we have to dereference the pointer and do the += else the addition happen on pointer address 
	{
		for(int i=0;i<size;i++)
		{
			this->a[i]+=ref;
			this->b[i]+=ref;
		}
	}

	void operator-=(const int & ref )  // cpp looks for operator-=(Structure* , int) be carefule we have to dereference the pointer and do the += else the addition happen on pointer address 
	{
		for(int i=0;i<size;i++)
		{
			this->a[i]-=ref;
			this->b[i]-=ref;
		}
	}


	~Structure()
	{
		delete [] a;
		delete [] b;
	}

};

mutex m1, m2; // 2 mutex for locking 2 thread and we are going to use scoped lock 

void func(Structure * ptr)
{
	cout<<"@void func(Structure * ptr)\n";
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(1234));
		auto endTime = std::chrono::high_resolution_clock::now();
		{
			lock_guard<mutex>l1(m1);
			lock_guard<mutex>l2(m2);
			*ptr+=23;
		}
		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<< "Time taken on func " << i << " iteration  = " << dura.count() <<endl;	
	}
}

void func1(Structure * ptr)
{
	cout<<"@void func1(Structure * ptr)\n";
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(1234));
		auto endTime = std::chrono::high_resolution_clock::now();
		{
			// prev thread order m1 -> m2 
			// this thread order m2 -> m1 for dead lock to happen 
			lock_guard<mutex>l2(m2);
			lock_guard<mutex>l1(m1); 
			*ptr-=23;
		}
		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<< "Time taken on func1  " << i << " iteration  = " << dura.count() <<endl;	
	}
}


int main()
{
	cout<<"This is the program to undedrstand the pointer passed as arg \n";
	int array [] = {12,23,34,45,56};
	float arrayf [] = {12.12,34.23,65.34,67.34,76.56};
	
	Structure * ptr = new Structure(5);
	ptr->a = array;
	ptr->b = arrayf;
	
	cout<<"Before thread -- \n";
	cout<<*ptr;
	cout<<"------------------\n";
	
	thread t1(func, std::ref(ptr));
	thread t2(func1, std::ref(ptr)); // thisis called only after the thread1 (t1) get executed fully because of join 
	t1.join();
	t2.join();
	cout<<"After thread ------\n";
	cout<<*ptr;
	cout<<"------------------\n";
}