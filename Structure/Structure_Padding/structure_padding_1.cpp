#include <iostream>
using namespace std;

struct A 
{
	public :
		int i;
		char c;
		double d;
};

int main()
{
	cout<<"Sizeof structure is : " << sizeof(A) <<endl; 

	// RULE 
	// element should be placed in an address which should be div by its alignment 
	// the size of structure should be mul of size of largest element in structure 

	// byte 0 - 3 i // int 
	// byte 4 c //char 
	// byte 5 -7 padded 
	// byte 8 -15 d // double 
	//curr size  = 16 // that is mul of 8 so size will be 16 

}