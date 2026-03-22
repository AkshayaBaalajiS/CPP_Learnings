#include <iostream>
using namespace std;

int main()
{
	cout<<"This is the program to understand the new, delete , malloc, free\n";

	int * ptr = (int *)malloc(5 * sizeof(int));
	delete [] ptr;

	int * ptr1 = new int[5];
	free(ptr);

	
}