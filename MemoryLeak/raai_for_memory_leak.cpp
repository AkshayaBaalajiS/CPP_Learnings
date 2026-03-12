#include <iostream>
#include <memory>
using namespace std;

int main()
{
	cout<<"This is the program to understnd the memory leak in cpp \n";
	unique_ptr<int *> ptr = make_unique<int *>(new int[10]);
	int arr[] = {12,23,34,45,65};
	ptr =make_unique<int *>(arr); // here on the move the delte will be called an the resource pointer set to null 

}