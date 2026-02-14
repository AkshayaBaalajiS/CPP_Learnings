#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	cout<<"Memcpy in cpp \n";
	char arr[] = "Akshaya Baalaji S\n";

	// char * ptr ; // if ptr not allocated we will have issue 
	char * ptr = new char [100];  
	memcpy(ptr, arr, sizeof(arr));

	cout<<"-- Char array = "  << arr <<endl;
	cout<<"-- Char pointer = "  << ptr <<endl;

	strcpy(ptr, "CustomValue");
	// modern way 

	copy(ptr, ptr+10,arr);

	cout<<"-- Char array = "  << arr <<endl;
	cout<<"-- Char pointer = "  << ptr <<endl;
}