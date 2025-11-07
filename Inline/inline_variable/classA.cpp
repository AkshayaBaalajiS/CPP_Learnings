#include "header.h"

void A::fucntionFromAClass()
{
	cout<<"@ void A::fucntionFromAClass() \n";
}

ostream & operator << (ostream & out, A & ref)
{
	out<<"A class object printed  \n";
	return out;
}
