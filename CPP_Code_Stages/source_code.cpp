#include <iostream>
#include <cstring>
#include <memory>
using namespace std;

int globalvariable ;

int globalvariable1 = 223;

class A 
{
	public :
	int * ptr ;
	const char * ptr1 ; // value cant be changed address can be changed 
	char * const ptr11; // address cant be changed value can be changed 
	char array[50];
	char array1[50];
		A() : ptr(new int [10]), /* mul initia ptr1(new char [50]), ptr11(new char[50]),*/  array("Akshaya baalaji S "), array1("Baalaji senthilraj"), ptr1(array), ptr11(array1)
		{
			cout<<"@ A class constructor \n";
			// not possible 
			// strcpy(ptr1, array);
			ptr1 = array; // this is also possible 
		}

		~A()
		{
			cout<<"@ A class destructor \n";
		}
};
int main()
{
	cout<<"This is the program to undertsand the cpp code example code is unique_ptr in cpp \n";
	char array[50];
	char * ptr = "Akshaya baalaji";
	strcpy(array, ptr);
	unique_ptr<A> unique1 = make_unique<A>();

	std::cout<<"Value ptr1 = " << endl;
	cout<<"ptr1 =  " << unique1->ptr1 <<endl;

	unique1->ptr1 = array; // address casn be changed value ptr1 cant be changed 
	// unique1->ptr1[0] = "a"; // assignment of read-only location
	std::cout<<"Value ptr1 After changing value  = " << endl;
	cout<<"ptr1 =  " << unique1->ptr1 <<endl;

	std::cout<<"\n\nValue ptr11 = " << endl;
	cout<<"ptr11 =  " << unique1->ptr11 <<endl;

	// unique1->ptr11 = array; // address cast be changed value ptr11 can be changed // assignment of read-only member
	unique1->ptr11[0] ='b'; 
	std::cout<<"Value ptr11 After changing value  = " << endl;
	cout<<"ptr11 =  " << unique1->ptr11 <<endl;
}