#include <iostream>
using namespace std;

template <typename T>
class A
{
	public :
		A()
		{
			cout<<"@ A class constructor and template type is : " << typeid(T).name() <<endl;
		}
		A(T arg)
		{
			cout<<"@ A class parameterized constructor and template type is : " << typeid(T).name() <<endl;
		}
};

int main()
{
	A obj = 12; // through the arg it is deducting the template 

}