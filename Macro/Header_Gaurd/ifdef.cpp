#include <iostream>
#include <functional>
using namespace std; 

#define DEFINE_MACRO
int main()
{
	cout<<"This is the program to understand the header gaurd working in C++\n";

	#ifdef DEFINE_MACRO
	std::function<void(int &)> lambda1 = [] (int & a ) {
		a++;
	};	
	#endif
	
	// even when the macro is defined only the error made inside the macro will be shown 

	int number= 123;

	// when we are using function which is defined in ifdef without the macro defined we will have error cause the function wont be visible outside of the macro unless it is defined  
	lambda1(number);

	cout<<"after function call to lambda1(number) the number =  " << number <<endl;  
}