#include <iostream>

struct Structure
{
	int a;
	char c;
	double d;
	double  b ;
	void print();
	friend std::ostream & operator<< (std::ostream & out, Structure & ref);
};