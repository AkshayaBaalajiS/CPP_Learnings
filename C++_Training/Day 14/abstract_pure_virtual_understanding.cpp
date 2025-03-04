#include<iostream>
using namespace std ;
class abstract_class 
{
	public :
		int private_variable = 30;
		virtual void function () = 0 ;   // this is the pure virtual function 
		void normal_function()
		{
			cout<<"Abstract class function \n";
		}
};
class derived_abs_class : public abstract_class {
	public:
		// void function_98() override 
		// {
		// 	cout<<"Definition from the Derived abs class : "  << private_variable  << "\n";	
		// }
};
class derived_class : public abstract_class
{
	public :
//		int private_variable=23 ; if it is the same variable of abstract_class 
		void function()
		{
			cout<<"Definition from the Derived class : "  << private_variable  << "\n";	
		}	
};
int main()
{
	derived_class object ;
	cout<<"---------------------------------\n";
	object.function();
	cout<<"---------------------------------\n";
	// derived_abs_class object_0; // empty class continues abstract 
	
}
    