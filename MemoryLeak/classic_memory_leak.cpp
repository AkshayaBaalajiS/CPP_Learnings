#include <iostream>
using namespace std;

int main()
{
	cout<<"This is the program to understnd the memory leak in cpp \n";
	int * ptr = (int * )malloc(sizeof(int)*5);
	int arr[] = {12,23,34,45,65};

	ptr=arr;

}