#include <iostream>
using namespace std;

int main()
{
	cout<<"This is the program to understand the double pointer working \n";

	int arr[] = {1,2,3,4,5};
	
	int * ptr = arr ;

	cout<<"Array[0] " << arr[0] << "  Address of first array  =  " << &arr << " address of first element = " << &arr[0] << "  \nAddress of pointer  = " << &ptr << "   pointer holds  " << ptr   << endl;


	int ** dPtr  = &ptr ;

	cout<<"Double pointer  " << **dPtr << " Address of poiner  " << dPtr << "  *dptr = " << *dPtr << " **dPtr  = " << **dPtr << endl;   
}