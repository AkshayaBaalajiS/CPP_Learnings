#include <iostream>
using namespace std;

decltype(auto) function_1 (auto a)
{
	return a;
}

int main()
{
	cout<<"Function return type set to decltype \n";

	auto a = function_1(7);
	cout<<" A = " << a << " Type =  " << typeid(a).name() <<endl;

	auto b = function_1(9.0f);
	cout<<" B = " << b << " Type =  " << typeid(b).name() <<endl;
	
	auto c = function_1(34.34);
	cout<<" C = " << c << " Type =  " << typeid(c).name() <<endl;
	
	auto d = function_1('d');
	cout<<" D = " << d << " Type =  " << typeid(d).name() <<endl;
	
	auto e = function_1("sedfsdgf");
	cout<<" E = " << e << " Type =  " << typeid(e).name() <<endl;
	
}