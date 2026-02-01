#include <iostream>
#include <cstring>
#include <chrono>
#include <thread> // pthread and this_thread
using namespace std;

struct A 
{
	int a ;
	char * ptr;
	string name;
	float roll;
};

void * function1(void * args)
{
	cout<<"void function1()\n";
	for(int i=0;i<10;i++)
	{
		auto start_time = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(5234));
		auto end_time = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time);
		cout<<"Iteration " << i << " = "<< duration.count() << endl;
	}
	return nullptr;
}

void * function2(void * args )
{
	cout<<"void function2()\n";
	A * ptr = static_cast<A *>(args);
	for(int i=0;i<10;i++)
	{
		auto start_time = std::chrono::high_resolution_clock::now();
		std::this_thread::sleep_for(std::chrono::milliseconds(534));
		auto end_time = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time);
		cout<<"iteration " << i << " = "<< duration.count() << endl;
	}
	ptr->a = 12;
	ptr-> name = "Akshaya Baalaji S ";
	ptr->roll = 12.234f;
	ptr->ptr = new char[50];
	strcpy(ptr->ptr, "Akshay");
	
	return static_cast<void*>(ptr);
}


int main()
{
	cout<<"This is the program to understand thread in cpp \n";

	pthread_t thread1;
	pthread_t thread2;

	A * ptr =  new A();

	pthread_create(&thread1, nullptr, function1, nullptr);
	pthread_create(&thread2, nullptr, function2, ptr);

	pthread_join(thread1, nullptr);
	void * ptrr = static_cast<void *>(ptr);
	pthread_join(thread2, &ptrr);

	cout<<"--------------------\n";
	cout<<ptr->a<<endl;
	cout<<ptr->name<<endl;
	cout<<ptr->ptr<<endl;
	cout<<ptr->roll<<endl;
	
	cout<<"--------------------\n";

}