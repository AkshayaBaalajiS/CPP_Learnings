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

		// we are commenting the tuple return and doing structure binding without tuple 
		// tuple <int , float, char , double, string> operator()()
		// {
		// 	cout<<"@ tuple <int , float, char , double, string> operator()() \n";
		// 	return make_tuple(a,b,c,d,e);
		// }

		~A()
		{
			cout<<"@ A class destructor \n";
		}
};

int main()
{
	cout<<"This is the program to understand the structure binding without the tuple\n";

	A object(12,12.121f,'a',32232.2233232,"Akshaya Baalaji Senthilraj");

	// auto[a,b,c,d,e] = object;
	// int [a,b,c,d,e] = object; // this will not work cause of below reason 
	/*
Why only auto?

Because the compiler needs to deduce multiple types at once. Each element can have a different type (e.g. int, double, std::string). C++ has no syntax to express "multiple variable types" in a single declaration other than auto.
	*/

	cout<<"A = " << a <<endl;
	cout<<"B = " << b <<endl;
	cout<<"C = " << c <<endl;
	cout<<"D = " << d <<endl;
	cout<<"E = " << e <<endl;
}