#include <iostream>
#include <tuple>
using namespace std;

struct A
{
	public :
		int a;
		float b ;
		char c;
		double d;
		string e;

		A(int a, float b, char c, double d, string e) : a(a), b(b), c(c), d(d), e(e)
		{
			cout<<"@ A struct constructor \n";
		}

		// tuple operator()      
		std::tuple<int, float, char, double, std::string> operator()()	
		{
			static tuple tuple_1 = make_tuple(a,b,c,d,e);
			return tuple_1;
		}

		~A()
		{
			cout<<"@ A struct destructor \n";
		}

		
};


int main()
{
	cout<<"This is the program for understanding the structure binding working in C++\n";
	int a;
	float b;
	char c;
	double d;
	string e;

	A obj (12,23.23f, 'a', 23.344554, "Akshaya Baalaji");
	tie(a,b,c,d,e) =  obj();

	cout<<"A = " << a <<endl;
	cout<<"B = " << b <<endl;
	cout<<"C = " << c <<endl;
	cout<<"D = " << d <<endl;
	cout<<"E = " << e <<endl;

}