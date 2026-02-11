#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	cout<<"memst code in cpp \n";
	int arr[] = {12,23,34,54,56,67};

	int * ptr =  new int[10];


	for(int i=0;i<6;i++)
	{
		cout<<arr[i]<<"  " ;
	}
	cout<<std::endl;

	memset(arr,0, sizeof(arr));

	for(int i=0;i<6;i++)
	{
		cout<<arr[i]<<"   " ;
	}
	cout<<endl;

	// modern memset 
	std::fill(arr,arr+6, 1);
	// array semantics 
	// array addition 
	// arr address is 1000 
	// number is 6
	//type is int 
	// arr+6 compiler convert the above to 
	// 1000 + sizeof(T) * number

	for(int i=0;i<6;i++)
	{
		cout<<arr[i]<<"   " ;
	}
	cout<<endl;

}