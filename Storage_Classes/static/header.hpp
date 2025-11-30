#pragma once 
#include <iostream>
using namespace std;
extern  int globalvar;
/*
extern static  int globalvar;
extern and static cannot be used together

They are opposites, and cannot coexist.

extern → “visible everywhere”
static → “visible nowhere except this file”
*/

static int staGlovar=213;	
/*
static gives internal linkage

That means:

Every .cpp file gets its own independent variable named staGlovar

They do NOT conflict with each other

Linker sees multiple variables, but all are internal to each file → no confli
*/

class A
{
	public :
		A()
		{
			cout<<"@ A class constructor \n";
		}
		~A()
		{
			cout<<"@ A class destructor \n";
		}
};