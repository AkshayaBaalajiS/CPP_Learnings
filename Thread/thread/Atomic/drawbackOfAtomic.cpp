#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

#ifdef ATOMIC 
atomic<int> a ;
atomic<int> b;
#else
int a;
int b;
#endif
	
void func1()
{
	for(int i=0;i<1000;i++)
	{
		a++; // atomic on ++ // read load and write will be atomic 
		// cout<<"[func1] a =" << a <<endl; // cout in cpp internally uses mutex to lock the thread for printing  
		b++; // atomic on ++ // read load and write will be atomic 
		// cout<<"[func1] b =" << b <<endl; // cout in cpp internally uses mutex to lock the thread for printing  
	}
}
void func2()
{
	for(int i=0;i<1000;i++)
	{
		a++; // atomic on ++ // read load and write will be atomic 
		// cout<<"[func2] a =" << a <<endl; // cout in cpp internally uses mutex to lock the thread for printing  
		b++; // atomic on ++ // read load and write will be atomic 
		// cout<<"[func2] b =" << b <<endl; // cout in cpp internally uses mutex to lock the thread for printing  
	}
}

void observer()
{
	for (int i = 0; i < 100000; i++) {
		#ifdef ATOMIC
        int x = a.load();
        int y = b.load();
        #else
        int x= a;
        int y= b;
        #endif
        if (x != y) {
            cout << "MISMATCH a=" << x << " b=" << y << endl;
            break;
        }
    }
}

int main()
{
	cout<<"Simple code to show tyhe atomic \n";
	thread t3(observer);
	thread t1(func1);
	thread t2(func2);
	t2.join();
	t1.join();
	t3.join();
	cout<<"A = " << a <<endl;
	cout<<"B = " << b <<endl;

}
/*
Simple code to show tyhe atomic 
MISMATCH a=1284 b=1283
A = 2000
B = 2000

this si the output where we can see the atomic does not guarantewe concurrency 
*/
/*
Atomics guarantee correct final values.
They do NOT guarantee that multiple atomics change together as one unit.
*/

/*
abt cout in thread 
Key reason #1 (MOST IMPORTANT): std::cout is synchronized

This line is the hidden villain:

cout << "[func1] a =" << a << endl;

What actually happens internally

std::cout is thread-safe

It uses an internal mutex

While one thread is printing, the other thread cannot print

So your code effectively becomes:

lock(cout_mutex)
print a
unlock(cout_mutex)

*/

/* 
abt he atomics 
The statement:

“Atomics guarantee correct final values, but not grouped updates”
*/