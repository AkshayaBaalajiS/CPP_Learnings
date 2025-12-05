#include <iostream>
using namespace std;

struct A 
{
	public :
		char c;
		double d;
		int i;
};

int main()
{
	cout<<"Sizeof structure is : " << sizeof(A) <<endl; 

	// RULE 
	// element should be placed in an address which should be div by its alignment 
	// the size of structure should be mul of size of largest element in structure 

	// how 24 
	// how padding works 
	// byte 0 - c // char 
	// byte 1  - 7 padded 
	// byte 8 -15 d // double 
	// byte 16 - 19 i // int 
	// current size of struct is 20 an the next nearest mul is 24 

}