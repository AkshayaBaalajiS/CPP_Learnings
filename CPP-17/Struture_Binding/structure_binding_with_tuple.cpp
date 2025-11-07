#include <iostream>
#include <tuple>
using namespace std;

struct A 
{
	public:
		A(int a, float b, char c, double d, string e) : a(a),b(b), c(c), d(d), e(e)
		{
			cout<<"@ A class constructor \n";
		}

		int a;
		float b;
		char c;
		double d;
		string e;

		tuple <int , float, char , double, string> operator()()
		{
			cout<<"@ tuple <int , float, char , double, string> operator()() \n";
			return make_tuple(a,b,c,d,e);
		}

		~A()
		{
			cout<<"@ A class destructor \n";
		}
};

int main()
{
	cout<<"This is the program to understand the structure binding in C++\n";

	A object(1,21.34f, 'a', 34.343434, "String Value ");
	
	// We dont need to declare the variable cause in auto we are declaring and initializing 
	// int a;
	// float b;
	// char c;
	// double d;
	// string e;

	auto [a,b,c,d,e] = object(); // the syntax [] is the structured binding 

	cout<<"A = " << a <<endl;
	cout<<"B = " << b <<endl;
	cout<<"C = " << c <<endl;
	cout<<"D = " << d <<endl;
	cout<<"E = " << e <<endl;
	



}