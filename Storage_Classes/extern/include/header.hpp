#pragma once 
#include <iostream>
using namespace std;

// int globalVar;
extern int globalVar;
class A 
{
	public :
		A()
		{
			cout<<"@ A class constructor\n ";
		}

		~A()
		{
			cout<<"@ A class destructor]\n";
		}
};

class B 
{
	public :
		B();

		~B();
};

#ifdef GUARD
extern void fucntion1();
#endif
/* pragma once understadnign 
#pragma once does NOT prevent multiple definitions across different .cpp files.

It only prevents duplicate includes within the SAME .cpp file.

But you included the header in TWO DIFFERENT .cpp files →

the definitions still appear twice → linker error.
*/