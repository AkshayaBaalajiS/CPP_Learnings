#include <iostream>
#include <thread>
#include <mutex>

using namespace std;


	
void func1(atomic<int> & a)
{
	for(int i=0;i<10;i++)
	{
		a++; // atomic on ++ // read load and write will be atomic 
	}
}

int main()
{
	cout<<"Simple code to show tyhe atomic \n";
	atomic<int> a {234};
	thread t1(func1, std::ref(a));
	t1.join();
	cout<<"A = " << a <<endl;

}