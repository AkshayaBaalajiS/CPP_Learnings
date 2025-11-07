#include <iostream>
using namespace std;

int return_square_integer(int a)
{
	static int some_var = a * a;
	return some_var;
}

int & return_square_integer_reference(int a)
{
	// return a*a;
	// this will create error cause return is int * const (some address and we are giving a int as return unable to convert )
	static int some_var = a * a;
	return some_var;
}


int main()
{
	int number = 23;

	int result = return_square_integer(number);

	// int & ref_num = 234; // this cant be done cause int & will work like int * const so here the value can be changed but the address cant be changed 
	/*
	error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
	*/

	int && ref = 234 ; // this can be done right side is expecting a rvalue and we are giving a rvalue 

	// int && ref_1 = number ; // this cant be done cause right side is expecting a rvalue and we are giving a lvalue  
	/*
	cannot bind rvalue reference of type ‘int&&’ to lvalue of type ‘int’
	*/

	cout<<"Number = " << number << "  Square = " << result << endl;


	// int & ref_result = return_square_integer(5); // here we cant use this function cause it is returning a integer and here it expects a int * const (some address) 
	int & ref_result = return_square_integer_reference(5);

	cout<<"Number 1 = " <<  5 << "  Square -  " << ref_result <<endl; 

	cout<<"Simple print  - " << return_square_integer_reference(5) <<endl;

/*
Does it return an address?

Technically, a reference is not returned as a raw address (like int* would), but under the hood it’s bound to the address of some_var.

So conceptually, yes — you are giving the caller direct access to the storage location (address) of some_var.
*/	

	int number_34 = 34 ;

	int & ref_34 = number_34;

	cout<<"number_34 = " << number_34 << "  ref_34 = " << ref_34  <<endl;

	number_34 = 72 ;
	cout<<"After changing the value of number_34 \n";
	cout<<"number_34 = " << number_34 << "  ref_34 = " << ref_34  <<endl;

	// the reference value will also get changed cause they point to same mem location 


}

