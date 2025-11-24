#include <iostream>
using namespace std;

struct A
{
	public :
		int a ;
		char b ;
		string c;
		float d;
		double e ;
		A() : a(1), b('a'), c("Akshaya Baalaji S "), d(12.2342f), e(3234.23423)
		{
			cout<<"@ A struct constructor \n";
		}

		// copy constructor // created for understanding the structure binding 
		A( A& obj) 
		{
			cout<<"@ A struct Copy constructor \n";
			this->a = obj.a;
			this->b = obj.b;
			this->c = obj.c;
			this->d= obj.d;
			this->e= obj.e;
		}

		~A()
		{
			cout<<"@ A struct destructor \n";
		}
};

int main()
{
	A obj;

	auto [a,b,c,d,e] = obj; // @ A struct Copy constructor called 
	/*
	internally 
		auto __tmp = obj;  // <--- This is an extra OBJECT
			int a = __tmp.a;
			char b = __tmp.b;
			string c = __tmp.c;
			float d = __tmp.d;
			double e = __tmp.e;
	*/
    cout << a << "\n";
    cout << b << "\n";
    cout << c << "\n";
    cout << d << "\n";
    cout << e << "\n";

	// Now any change on a will modify obj.a also.
	auto& [f, g, h, i, j] = obj;
}


/** 
Why destructor called 2 times 
	auto [a,b,c,d,e] = obj;
 * 
 Creates a temporary hidden copy of obj inside the compiler-generated binding structure.

This temporary object is also of type A, and its destructor runs too.
 */