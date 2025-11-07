#include<iostream>
using namespace std ;

class A 
{
    // int private_variable;
    public:
        A()
        {
            cout<<"@ A class constructor " << this <<"\n";
        }
        void function() // this funciton is hidden (function hiding )
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
    // int private_variable_1;
    public:
        B()
        {
            cout<<"@ B class constructor " << this <<"\n";
        }
        /*
        if the function is not there the compiler searches whether 
        it is derived class or not if derived then go to the base class from where it is 
        derived and search for that function if it is not there compiler searches it is derived or not and this continuous 
        */ 
        void function()
        {
            cout<<"Derived class function\n";
        }
        ~B()
        {
            cout<<"@ B class destructor " << this <<"\n";
        }
};

int main()
{
    {   
        B object ;
        object.function();  
        /* this hides the function of the base class because there is a function with same name in derived class */ 
    }

    B object;
    
    // A object_1 ;
    // object_1.function();
    //      or 
    object.A::function();  // another way to call the base class function 
}