#include <iostream>
using namespace std;

constexpr int varInHeader = 43;  // constexpr implies inline for variables.
/*
constexpr Compile-time constant: The value must be known and computable at compile time. 

*/

/*
// int varInHeader = 43; // when we declare normally we will get multiple definition error  
/usr/bin/ld: /tmp/ccsPcjvX.o:(.data+0x0): multiple definition of `varInHeader'; /tmp/ccZvpb5Z.o:(.data+0x0): first defined here
/usr/bin/ld: /tmp/ccgClwt5.o:(.data+0x0): multiple definition of `varInHeader'; /tmp/ccZvpb5Z.o:(.data+0x0): first defined here
collect2: error: ld returned 1 exit status

*/
inline int varInHeaderWithInline = 56; 
/*
inline for variable or function 
Allows the variable/function to be defined in multiple translation units, but the linker merges them into one definition.
*/


/*
Use constexpr when the value is a true compile-time constant.

Use inline when you want a single global variable or function definition across TUs, but its value may be runtime.

*/
class A
{
	public:
		A(){
			cout<<"@ A class constructor \n";
		}
		void fucntionFromAClass() ;
		~A(){
			cout<<"@ A class destructor \n";
		}
		friend ostream & operator << (ostream & out, A & ref);
};

class B
{
	public:
		B(){
			cout<<"@ B class constructor \n";
		}
		void functionFromBClass();
		~B(){
			cout<<"@ B class destructor \n";
		}
		friend ostream & operator << (ostream & out, B & ref);
};

