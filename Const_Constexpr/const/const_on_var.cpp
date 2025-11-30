#include <iostream>

using namespace std;

int main()
{
	cout<<"This is the program to understand the const on varaible \n";
	const int a=23;
	// a=234; // the variable cant be changed 
	int b=23;
	const int * ptr = &b;
	cout<<"ptr is the var where const applied on the value \n";
	cout<<"before b value change * ptr = " << *ptr<<endl;
	b=45;
	cout<<"*after b value change ptr = " << *ptr<<endl;
	// *ptr = 234; // this cant be done 
	int c=234;
	ptr = &c; // this can be done cause the const applied on value 
	cout<<"after the address change *ptr = " << *ptr <<endl;

	int * const p = &c;
	cout<<"p is the pointer where the const is applied on pointer \n";
	cout<<"before *p value change  *p =  " << *p <<endl;
	*p =456;
	cout<<"after *p value change  *p =  " << *p <<endl;
	cout<<"C value after *p change c= " << c <<endl;
	// p = &b; // this canr be done causer the p is const on poiunter  
}