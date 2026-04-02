#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	cout<<"This is the code to understand the malloc doing shallow copy\n";
	int * ptr = new int(123);
	int * ptr1 = new int(67);

	int ** arr = new int*[2];
	arr[0] = ptr;
	arr[1] = ptr1;

	int ** arr1 = new int*[2];

	cout<<"--- BEFORE MEMCPY --------------\n";
	for(int i=0;i<2;i++)
	{
		cout<<"*arr[" <<  i << "]=" << *arr[i] <<endl;		
	}
	
	// for(int i=0;i<2;i++)
	// {
	// 	cout<<"*arr1[" <<  i << "]=" << *arr1[i] <<endl;		
	// }
	
	cout<<"--------------------------------\n";
	// here malloc does shallow copy both will have the same address 
	memcpy(arr1, arr, sizeof(int *) * 2);
	
	cout<<"--- AFTER MEMCPY --------------\n";
	for(int i=0;i<2;i++)
	{
		cout<<"*arr[" <<  i << "]=" << *arr[i] <<endl;		
	}
	
	for(int i=0;i<2;i++)
	{
		cout<<"*arr1[" <<  i << "]=" << *arr1[i] <<endl;		
	}
	
	cout<<"--------------------------------\n";
	
	*(arr[0]) = 345;
	*(arr[1]) = 345;
	
	// in the below print there will eb the change in the arr1 also cause due to shallow copy both the arr and arr1 element have same address 
	cout<<"--- AFTER CHANGE ON ARR --------------\n";
	for(int i=0;i<2;i++)
	{
		cout<<"*arr[" <<  i << "]=" << *arr[i] <<endl;		
	}
	
	for(int i=0;i<2;i++)
	{
		cout<<"*arr1[" <<  i << "]=" << *arr1[i] <<endl;		
	}
	
	cout<<"--------------------------------\n";


}