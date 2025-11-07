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
        void add(double a)
        {
            cout<<"Base class function " <<a<< "\n";          
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
        void add(int a , int b )
        {
            cout<<"Derived class Add function " <<a+b << "\n";
        }
        void add(double a, double b)
        {
            cout<<"Base class function " <<a+b<< "\n";          
        }
        ~B()
        {
            cout<<"@ B class destructor " << this <<"\n";
        }
};

int main()
{
    B object;
    //overloadin done here 
    object.add(10,20);   
    object.add(10.23,2.33);
    object.A::add(12);
    

}