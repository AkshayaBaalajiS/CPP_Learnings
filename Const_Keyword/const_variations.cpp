#include <iostream>
using namespace std;

int main()
{
	int number =123;
	
	const int * arr = new int[2];
	// int const * arr = new int[2];
	// the above both declaration of pointer of type int are same 

	// the below cant be done cause assignment of read only 
	// we have given const before type so the value cant be changed and the address can be changed 
	/* 
	arr[0] = number;
	arr[1] = number;
	*/

	int array [] = {1,2,3,4,5};

	arr = array ; // address assignment will work 
	cout<<"The array of index 1  =  " << arr[1] <<endl;
	cout<<"The array of index 2  =  " << arr[2] <<endl;
	cout<<"The array of index 3  =  " << arr[3] <<endl;
	cout<<"The array of index 4  =  " << arr[4] <<endl;


	int * const  arr_1 = new int [5];
	
	// arr_1 = array ; // address assignment will not work here 
	arr_1[0]=23;
	arr_1[1]=123;
	arr_1[2]=234;
	arr_1[3]=2345;
	arr_1[4]=23456;

	cout<<"The array_1 of index 1  =  " << arr_1[1] <<endl;
	cout<<"The array_1 of index 2  =  " << arr_1[2] <<endl;
	cout<<"The array_1 of index 3  =  " << arr_1[3] <<endl;
	cout<<"The array_1 of index 4  =  " << arr_1[4] <<endl;




}