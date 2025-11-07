#include <iostream>
#include <cassert>
using namespace std;


int main()
{
	cout<<"This is the program to see how th static assert works \n";
	int size =5; 
	/*
	The below cant be done cause : 
		size is a  runtime varaible not a compile time constant 
		static_assert must be evaluated at runtime 
		static_assert only works with compile-time constants (const, constexpr, template parameters).
		Normal variables are not allowed.

	static_assert(size >=5, "ASSERT : The size is lesser than 5 "); 
	
	size = 2;
	static_assert(size >=5, "ASSERT : The size is lesser than 5 ");
	*/

	assert(size >=5 ); //, "ASSERT: The size is lesser than 5 ");
	
	size=2;		
	assert(size >=5 ); //, "ASSERT: The size is lesser than 5 ");

}