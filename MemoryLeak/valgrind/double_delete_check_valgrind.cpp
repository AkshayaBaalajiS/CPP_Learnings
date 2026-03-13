#include <iostream>
using namespace std;

int main()
{
	cout<<"This is the code to understand the valgrind \n";
	int * ptr= new int[100]; // 100 * 4 
	int * ptr1 = new int[1000]; // 1000 * 4
	// total heap == 4000 + 400 

	ptr1= ptr; // mem leak on ptr1 

	delete [] ptr;
	delete [] ptr1;
}