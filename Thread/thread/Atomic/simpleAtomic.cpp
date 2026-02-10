#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

atomic<int> a ;
	
void func1()
{
	for(int i=0;i<10;i++)
	{
		a++; // atomic on ++ // read load and write will be atomic 
	}
}

int main()
{
	cout<<"Simple code to show tyhe atomic \n";
	thread t1(func1);
	t1.join();
	cout<<"A = " << a <<endl;

}