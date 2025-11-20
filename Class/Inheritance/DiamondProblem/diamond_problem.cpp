#include <iostream>
using namespace std;

struct A
{
	A()
	{
		cout<<"@ A class constructor \n";
	}

	~A()
	{
		cout<<"@ A class destructor \n";
	}	
};

struct B : virtual public A
{
	B()
	{
		cout<<"@ B class constructor \n";
	}

	~B()
	{
		cout<<"@ B class destructor \n";
	}	
};

struct C : virtual public A
{
	C()
	{
		cout<<"@ C class constructor \n";
	}

	~C()
	{
		cout<<"@ C class destructor \n";
	}	
};

struct D : virtual public B, public C
{
	D()
	{
		cout<<"@ D class constructor \n";
	}

	~D()
	{
		cout<<"@ D class destructor \n";
	}	
};

	

int main()
{
	cout<<"This is the program to understand the diamond problem in cpp \n";
	D * ptr = new D();
	delete ptr;

}