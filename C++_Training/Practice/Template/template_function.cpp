#include<iostream>
#include<typeinfo>
using namespace std ;

//template <t>
//t template_function(t ref)
//{
//	return (ref+ref);
//}

template <typename t >
void template_function(t & ref , t& ref2) 
{
	int temp =ref ;
	ref = ref2 ;
	ref2 = temp ; 
}

int main()
{
	cout<<"-------------------------------------------------------------\n";
	int a =10 ;
	int b=20 ;
	cout<<"A = " << a << "  B = " << b << "\n";
	cout<<"-------------------------------------------------------------\n";
	template_function(a,b);
	cout<<"Changed ....\n";
	cout<<"A = " << a << "  B = " << b << "\n";
	cout<<"-------------------------------------------------------------\n";
	
}
