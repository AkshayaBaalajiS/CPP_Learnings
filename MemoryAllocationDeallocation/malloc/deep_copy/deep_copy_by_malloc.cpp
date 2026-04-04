#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	cout<<"This is the program to understand the malloc for the deep copy \n";

	int * ptr = new int[100];
	for(int i=0;i<100;i++)
	{
		ptr[i] = i+i*2;
	}

	int * ptr1 = (int *)malloc(sizeof(int) * 100);
	memset(ptr1, 0, sizeof(int)*100);
	
	cout<<"--- BEFORE MEMCPY --------------------\n";
	for(int i=0;i<100;i++)
	{
		cout<< ptr[i] << " " ;
	}
	cout<<endl;
	for(int i=0;i<100;i++)
	{
		cout<< ptr1[i] << " " ;
	}
	cout<<"-----------------------------------\n";

	// the array element are the values so here deep copy happens 
	memcpy(ptr1, ptr, sizeof(int) * 100);

	cout<<"--- AFTER MEMCPY ---------------\n";
	for(int i=0;i<100;i++)
	{
		cout<< ptr[i] << " " ;
	}
	cout<<endl;
	for(int i=0;i<100;i++)
	{
		cout<< ptr1[i] << " " ;
	}
	cout<<"-----------------------------------\n";

	

}