#include <iostream>
#include <memory>
using namespace std;

int main()
{
	cout<<"Program to understand the memory leak \n";
	int arr[] ={12,23,34,45,56,76};
	int * ptr = new int[12];

	// below is the situation where memory leak happens 
	ptr= arr;
	cout<<"Ptr holds arr " << ptr[0] << " " << ptr[1] << " " << ptr[2] << " " << ptr[3] <<endl;

	unique_ptr<int []> uniq = make_unique<int[]>(10);
	uniq = make_unique<int []>(20); // here the old pointer is auto freed 
}