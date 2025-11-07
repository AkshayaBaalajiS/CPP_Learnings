#include<iostream>
using namespace std ;

namespace Group1
{
	
	class A
	{
	// a simple class for showing the auto can work on userdefined datatypes 	
	};
	class B : public A 
	{
		
	};
	
	void add_find(int ptr )
	{
		cout<<"ptr hold : " << ptr   << " address is   " << &ptr <<"\n";
	}
	
	void main()
	{
		cout<<"Group1::main     : " << "\n";
		int i=10 ;	
		auto inval = 200 ;  
		auto dval = 34534.23200 ;  
		auto fval = 34534.20f ;  
		A object ;
		auto a_obj = object ;
		auto aa_obj = new A();
		
		// static_cast is done with auto automatically 
		auto aaa_obj = new B();
		// now the compiler has a overhead and we are informing the compiler to do a exec from right to left 
		cout<<"-------------------\n";
		cout<<"typeid(i).name()     = " << typeid(i).name()<<"\n";
		cout<<"-------------------\n";
		cout<<"typeid(inval).name()     = " << typeid(inval).name()<<"\n";
		cout<<"-------------------\n";
		cout<<"typeid(dval).name()     = " << typeid(dval).name()<<"\n";
		cout<<"-------------------\n";
		cout<<"typeid(fval).name()     = " << typeid(fval).name()<<"\n";
		cout<<"-------------------\n";
		cout<<"typeid(a_obj).name()     = " << typeid(a_obj).name()<<"\n";
		cout<<"-------------------\n";
		cout<<"typeid(aa_obj).name()     = " << typeid(aa_obj).name()<<"\n";
		cout<<"-------------------\n";
		cout<<"typeid(aa_obj).name()     = " << typeid(aaa_obj).name()<<"\n";
		cout<<"-------------------\n";
		
		
		
	}	
}
int main()
{
	Group1::main();
	
}
/*
Auto :
	*auto helps the compiler to understand the datatype from the value without the variable datatype explicitly given 
	*initialization is must to find the type of variable by compiler 
	*auto can take care of userdefined datatypes also 
	*the static_cast can be done by the auto but the dynamic_cast cant be done by the 
	auto beacuse the dynamic_cast is on runtime and the static_cast is on compile time 

*/