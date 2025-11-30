#define GUARD // if the guard is not defined the multi def error will not come 
// we are defining the fucntion in 2 place now so multi def error comes to solve that use extern 
#include "header.hpp"

B::B()
{
	cout<<"2 B class constructor \n";
	cout<<"Global variable : " << globalVar<<endl;

}

B::~B()
{
	cout<<"2 B class constructor \n";
}

