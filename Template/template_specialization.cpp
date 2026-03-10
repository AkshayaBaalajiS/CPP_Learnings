#include <iostream>
using namespace std;

template <typename T>
class A 
{
	T a;
	public :
	A(T a) :  a(a)
	{
		cout<<"@ A class constructor \n";
		cout<<"a = " << a <<endl;
	}
};

template <>
class A<int>
{
	int a;
	public :
	A(int a) :  a(a)
	{
		cout<<"@ A<int> class constructor \n";
		cout<<"a = " << a <<endl;
	}
};



int main()
{
	cout<<"This is the program to udnerstand the class template \n";
	A<int *> aobj(new int[1]);
	A<int> aobj1(1);
}