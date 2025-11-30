#include <iostream>
#include "header.hpp"
#include "header1.hpp"

// int globalvar=234;// this defi is on other file 

int main()
{

	// staGlovar =124; // here it is working and it will not work at global scope cause in global scope 
	/*
	Variable definitions / declarations
	Function declarations / definitions
	Class / struct / enum / typedef / constexpr / inline variable declarations
	
	Which is not allowed in global scope 
	Assignment statements :
	Expressions / function calls / loops / if statements / etc.
	*/


	cout<<" static variable in usage in header and checking whether mul ef issue will come for the static variable\n";
	A  aobj;

	B bobj;
	cout<<"The static global var : " << staGlovar << endl;
}
