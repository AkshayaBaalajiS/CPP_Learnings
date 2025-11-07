#include <iostream>
using namespace std;


void function(int * arr, int size)
{
	cout<<"void function(int * arr, int size)\n";
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<endl;
	}
}
void function(int ** arr, int size)
{
	cout<<"void function(int ** arr, int size)\n";
	for(int i=0;i<size;i++)
	{
		cout<<*(arr[i])<<endl;
		arr = arr+1 ;
	}
}

int main()
{
	// int arry[2][5]= {{6,7,8,9,0},{2,3,4,5,3} }; // multi dim array 
	// int arry[]= {6,7,8,9,0};
	int * arry=  new int[5];
	arry[0]= 6;
	arry[1] =7;
	arry[2] =8;
	arry[3]=9;
	arry[4]=0;
	function(arry, 5);
	int * ptr =  arry;
	int **ptr_1 = &ptr ;// ptr is int * and &ptr is int **
	function(ptr_1, 5);
}