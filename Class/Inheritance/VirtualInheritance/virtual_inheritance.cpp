#include <iostream>
using namespace std;

struct A 
{
	public :
		A()
		{
			cout<<"@ A struct cons\n";
		}
		~A()
		{
			cout<<"@ A struct desc\n";
		}
};	

struct B : virtual public A
{
	public :
		B()
		{
			cout<<"@ B struct cons\n";
		}
		~B()
		{
			cout<<"@ B struct desc\n";
		}
};	

struct C : virtual public A
{
	public :
		C()
		{
			cout<<"@ C struct cons\n";
		}
		~C()
		{
			cout<<"@ C struct desc\n";
		}
};	

struct D : virtual public B, public C
{
	public :
		D()
		{
			cout<<"@ D struct cons\n";
		}
		~D()
		{
			cout<<"@ D struct desc\n";
		}
};	

int main()
{
	D obj;
	/*
	Without the virtual on inheritance used 
@ A struct cons
@ B struct cons
@ A struct cons
@ C struct cons
@ D struct cons
@ D struct desc
@ C struct desc
@ A struct desc
@ B struct desc
@ A struct desc
	*/
	/*
	After the virtual used onthe inheritance 
@ A struct cons
@ B struct cons
@ C struct cons
@ D struct cons
@ D struct desc
@ C struct desc
@ B struct desc
@ A struct desc

	*/
}