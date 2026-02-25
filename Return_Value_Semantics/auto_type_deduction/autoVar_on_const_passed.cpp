#include <iostream>
using namespace std;

int main()
{
	cout<<"This the code to udnerstand the auto variable on const passed it will not take the const \n";
	const int someVar = 324;
	const int * cptr = &someVar;
	cout<<"Type os someVar = " << typeid(someVar).name()<<endl;
	auto autVar = someVar; // auto does not hold the const 
	autVar = 34;	
	cout<<"Type os autVar = " << typeid(autVar).name()<<endl;

	decltype(auto) declAut = someVar; // holds the const also 
	// declAut = 234; // error assignment of readOnly operation 
	
}
