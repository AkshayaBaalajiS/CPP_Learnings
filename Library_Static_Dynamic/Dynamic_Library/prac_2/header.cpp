#include "header.hpp"

using namespace std;

A::A()
{
	cout<<"@ A class constructor \n";
}

A::~A()
{
	cout<<"@ A class destructor \n";
}

void A::print()
{
	cout<<"virtual void A::print()\n";
}

void A::function() 
{
	cout<<"@ virtual void A::function() \n";
}