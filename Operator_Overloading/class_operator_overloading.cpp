#include <iostream>
using namespace std;

class A 
{
	public :
	int a ;
	int b;
		A()
		{
			cout<<"@ A class constructor \n";
		}

		A(int a )  = delete ;
		// {
		// 	cout<<"A(int a ) : a(a)\n";
		// }

		A(int a , int b ) : a(a), b(b)
		{
			cout<<"A(int a , int b ) : a(a), b(b)\n";
		}

		~A()
		{
			cout<<"@ A class destructor \n";
		}

		friend ostream& operator<<(ostream & out, A & obj)
		{
			out<<"A class object printed \n";
			return out;
		}

		string operator() ()
		{
			return "Operator () overloading ";
		}

		int operator[] (int index)
		{
			return 0;
		}

		operator int ()
		{
			cout<<"operator int ()\n";
			return 0;
		}

		operator string ()
		{
			cout<<"operator string ()\n";
			return "";
		}

		
};

int main()
{
	A obj ;
	cout<<"<< operator overloading = "<< obj;

	/*
	Consider this expression:
	cout << obj;

	This is interpreted by the compiler as:
	operator<<(cout, obj);
	*/

	cout<<"() operator overloading = " << obj()<<endl;
	cout<<"[] operator overloading = " <<obj[0] <<endl;

	int a = obj;
	string b = obj;

	char c = obj;

	A obj1 = {12,23};

	A obj2  =23 ;
}