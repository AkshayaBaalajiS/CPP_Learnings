#include<iostream>
using namespace std ;

class A 
{
    int private_variable;
    public:
        A(int args=-1)  : private_variable(args) 
        {
            cout<<"@ A class constructor " << this <<"\n";
        }

        void base_function() 
        {
            cout<<"Base class function\n" ;
        }
        
        
        ~A()
        {
            cout<<"@ A class destructor " << this <<"\n";
        }
};

class B : public A 
{
    int private_variable_1;
    public:
        B(int args=-1) : private_variable_1(args)
        {
            cout<<"@ B class constructor " << this <<"\n";
        }

        void derived_function() // this funciton is hidden (function hiding )
        {
            cout<<"Base class function\n" ;
        }
        
        
        ~B()
        {
            cout<<"@ B class destructor " << this <<"\n";
        }
};

int main()
{
    B derived_object(12);
    A base_object(14);

    /*
    This below code cant be done according to liskov the 
    base class pointer can represent derived but not the derived class pointer represent base  
    
    B * derived_ptr = NULL ;
    derived_ptr= &base_object;
    */

    A * base_ptr = NULL ;
    base_ptr = &derived_object;

    // though it get represent to the derived class object it can only access the base class data members and member functions 
    // base_ptr->derived_function(); 
    base_ptr->base_function();  

    B * derived_ptr = NULL ;
    derived_ptr= &derived_object;

    // the derived class pointer can access all the data member and member functions from base and derived class too  
    derived_ptr->base_function();
    derived_ptr->derived_function();

}