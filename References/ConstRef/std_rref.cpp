#include <iostream>
#include <functional>
using namespace std;

int main()
{
	cout<<"Reference in cpp where std::ref used and why \n";
	int number = 234; 
	cout<<"number = " << number <<endl;
	int & ref = number;

	// int & ref1 = number+12 ; // lvalue ref to rvalue not permitted 
	// std::ref cant conver a rvalue to lvalue
	//  void ref(const _Tp&&) = delete;
	int & ref1 = std::ref(number+23) ;


}