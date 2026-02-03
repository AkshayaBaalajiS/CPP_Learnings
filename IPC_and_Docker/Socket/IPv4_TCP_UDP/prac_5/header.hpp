#include <iostream>

struct DataStructure
{
	int a ;
	char array[20];
	float c;
	double d;
	friend std::ostream & operator<<(std::ostream & out, DataStructure & ref);
};