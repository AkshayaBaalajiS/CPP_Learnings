#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	cout<<"This is the program to understand the char Ptr printing in cpp \n";
	string strrr("Akshaya Baalaji S");
	char * ptrr = const_cast<char *>(strrr.c_str());
	char * ptr = new char[100];
	char carray[] = "Akshaya Baalaji S ";
	char * cptr = carray;
	int legth = strlen(strrr.c_str());
	cout<<"Length of string = " << legth <<endl;

	copy(ptrr, ptrr+legth, ptr); // source begin, source end, destination to be given as parameter to copy 
	cout<<"------------------------\n";
	cout<< "carray = " << carray <<endl;
	cout<< "&carray = " << &carray <<endl;
	cout<<"------------------------\n";
	cout<< "cptr = " << cptr <<endl;
	cout<< "&cptr = " << &cptr <<endl;
	cout<<"------------------------\n";
	cout<< "Char * ptr = " << ptr <<endl;
	cout<< "Char * ptrr = " << ptrr <<endl;
	cout<<"------------------------\n";
	
	int array[] = {123,234,23,34,34};
	int * iptr =array ;

	cout<<"========================\n";
	cout<<"array =" << array <<endl;
	cout<<"&array =" << &array <<endl;
	cout<<"iptr =" << iptr <<endl;
	cout<<"*iptr =" << *iptr <<endl;
	cout<<"&iptr =" << &iptr <<endl;
	cout<<"========================\n";
	
}	