#include <iostream>
#define GUARD
#include "header.hpp"
#include "function.hpp"
void fucntion1()
{
	cout<<"@ function 1 in global header ";
}
using namespace std;
int globalVar = 223;
int main()
{
	A obj;
	cout<<"Global variable from header = " << globalVar << std::endl;
	B bobj;	
	fucntion1();
}