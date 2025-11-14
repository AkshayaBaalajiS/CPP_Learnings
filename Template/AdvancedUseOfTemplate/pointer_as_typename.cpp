#include <iostream>
#include <array>
using namespace std;

template <typename T>
void function (T arg, int size )
{
	for(int i=0;i<size;i++)
	{
		cout<<arg[i]<< " " << endl;
	}
}

template <typename T>
void function1 (T* arg, int size )
{
	for(int i=0;i<size;i++)
	{
		cout<<arg[i]<< " " << endl;
	}
}

int main()
{
	cout<<"This is the cpp code to understand the pointer passed as typename \n";
	// int [10] array  = {12,23,34,45,56,67,78,89,90,12}; //  expected identifier before numeric constant
	int array [10]  = {12,23,34,45,56,67,78,89,90,12};
	function(array, 10);
	
	function1(array, 10);
}

/*

Case 1: function(T arg)
template <typename T>
void function(T arg);
Call:
int array[10];
function(array);
Deduction:
•	array decays to int*
•	Parameter type is T
•	Therefore:
T = int*
arg = int*

Case 2: function1(T* arg)
template <typename T>
void function1(T* arg);
Call:
function1(array);
Deduction:
•	array decays to int*
•	Parameter type is T*
Matching:
T* = int*  
→ T = int



*/