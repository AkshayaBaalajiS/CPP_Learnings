#include <iostream>
#include <cstring>
#include <future>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

mutex m1;

struct Structure
{
	int data;
	char * cdata;
	float fdata;
	Structure() : cdata(new char[40]) {}
};

Structure * ptr = new Structure();

void function1(std::promise<int> p)
{
	for(int i=0;i<10;i++)
	{
		auto startTime =  std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(1234));
		auto endTime =  std::chrono::high_resolution_clock::now();
		std::unique_lock<mutex> ul(m1, std::defer_lock);
		{
			ul.lock();
			ptr->data = 234;
			ptr->fdata = 7689.234;
			// ptr->cdata = "Akshaya Baalaji Senthilraj";
			strcpy(ptr->cdata, "Akshaya Baalaji Senthilraj"); // deep copy of data 
			ul.unlock();
		}
		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"Duration for " <<  i << "  iteration on function1  = " << dura.count() <<endl;
	}
	p.set_value(687);
}


int main()
{
	cout<<"UNique lock : defer_lock , try_to_lock , timed_lock \n";
	int number ;
	std::promise <int> pro ;
	std::future <int> futur = pro.get_future();
	
	std::promise <int> pro1 ;
	std::future <int> futur1  = pro1.get_future();
	
	thread t1(function1, std::move(pro));
	t1.join();

	char * data = "Akshaya baalaji S ";
	char * cdata = new char [39];
	strcpy(cdata, data);
	cout<<"cdata = " << cdata <<endl;

}


/*

ptr->cdata = "Akshaya Baalaji Senthilraj"; // shallow copy 
strcpy(ptr->cdata, "Akshaya Baalaji Senthilraj");

what is the diuff bet these 2 ?


The primary difference between these two lines is that the first is a pointer assignment, while the second is a deep copy of data. 
1. Pointer Assignment (ptr->cdata = "...")
When you use the assignment operator, you are changing the address stored in ptr->cdata. 
How it works: It makes ptr->cdata point directly to a string literal stored in a read-only section of memory (like .rodata).
Mutability: You cannot modify this string later (e.g., ptr->cdata[0] = 'a' would cause a crash or undefined behavior).
Memory Risk: If ptr->cdata previously pointed to memory allocated with malloc(), that original memory is now lost (a memory leak) because you overrode the only handle to it. 


2. String Copy (strcpy(ptr->cdata, "...")) 
When you use strcpy, you are copying the actual characters into a memory buffer that ptr->cdata already points to. 
How it works: It performs a "deep copy," transferring each character (including the null terminator) from the source to the destination.
Mutability: If ptr->cdata points to a writable buffer (like an array or heap-allocated memory), you can safely modify the characters later.
Prerequisite: ptr->cdata must already point to a valid, writable memory block large enough to hold the string. If it points to NULL or a read-only literal, strcpy will crash. 

*/


/*

strcpy takes two char * (pointers) and performs a deep copy. It literally loops through the source string, copying one byte at a time to the destination until it hits the null terminator \0.

*/