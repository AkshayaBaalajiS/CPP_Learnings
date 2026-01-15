#pragma once 
#include <iostream>

class A 
{
	public :
		A() = default ;
		~A() = default ;
		A(A & arg ) = default ;
		A(A&& arg) = default ;
		A& operator= (A& arg) = default; 
		A& operator= (A&& arg) = default; 
};