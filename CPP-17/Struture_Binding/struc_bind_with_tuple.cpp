#include <iostream>
#include <tuple>
using namespace std;

struct A 
{
	int a;
	float b;
	char c;
	double d;
	string s;
	A(): a(12), b(23.234f), c('a'), d(456.45645), s("Akshaya Baalaji ")
	{}

	tuple<int, float, char, double, string> operator()()
	{
		return make_tuple(a,b,c,d,s);
	}
};	

int main()
{
	cout<<"This is the code to understand the structure binding in cpp \n";
	A obj;

	auto [a,b,c,d,e] = obj();
	cout<<obj.s<<endl;
	cout<<"A = " <<a  <<"  " <<  typeid(a).name()<<endl;
	
	cout<<"b = " <<b <<"  " <<  typeid(b).name()<<endl;

	cout<<"c = " <<c <<"  " <<  typeid(c).name()<<endl;

	cout<<"d = " <<d <<"  " <<  typeid(d).name()<<endl;

	cout<<"e = " <<e <<"  " <<  typeid(e).name()<<endl;
}