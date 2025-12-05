#include <iostream>
using namespace std;

int main()
{
	cout<<"@ this is the program to understand the volatile storage class in cpp \n";
	volatile int a =123;

	cout<<"Addr of volatile variable = " << a <<endl;
}

/*
The volatile keyword in C++ is a type qualifier that informs the compiler that the value of a variable may change at any time due to external factors, outside the normal flow of the program. This prevents the compiler from performing certain optimizations that might otherwise lead to incorrect or unexpected behavior. 
Key characteristics and uses of volatile:
Prevents Compiler Optimizations: When a variable is declared volatile, the compiler is instructed to always fetch the most up-to-date value from memory each time the variable is accessed, rather than relying on cached values in registers or performing other optimizations like reordering memory accesses.
*/