#include <iostream>
#include <cstring>
#include <memory>
using namespace std;

// below is the memory leak example if the string is empty the delte wont be called 
// the sol is you can add the delte before throw but if there are 10 error conditions we need 10 times delete so the modern solution is RAII
void memoryLeak(string strr)
{
	int * ptr = new int[1000];

	if(strr.empty())
	{
		throw std::runtime_error("string is empty ");
	}

	delete [] ptr;
}

// below is RAII implemented so if the function goes out of scope the resource is deallocated by unique_ptr 
void solutionforMemoryLeak(string strr)
{
	unique_ptr<int[]> up = make_unique<int[]>(10000);
	if(strr.empty())
	{
		throw std::runtime_error("string is empty ");
	}
}


int main()
{
	cout<<"This is the cde to see the memory leak function and the sol for it \n";
	try
	{
		string strr = "akshaya Baalaji";
		string strr1 = "";
		// memoryLeak(strr1); // here the delte is not called
		solutionforMemoryLeak(strr1); 
	}
	catch(std::exception & e)
	{
		cout<<"[EXCEPTION] = " << e.what() <<endl;
	}
}