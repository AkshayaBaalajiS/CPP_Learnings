#include <iostream>
using namespace std;

int main()
{
	char * ptr = (char *)malloc(10);
	ptr[11] ='a';

	char * ptr1 = new char[10];
	ptr1[11] ='a';

	
	free(ptr);
}