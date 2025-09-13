#include "header.h"

void B::functionFromBClass()
{
	cout<<"@ void B::functionFromBClass()\n";
}


ostream & operator << (ostream & out, B & ref)
{
	out<<"B class object printed  \n";
	return out;
}