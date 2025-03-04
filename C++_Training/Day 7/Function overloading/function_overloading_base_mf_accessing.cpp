
// the overloading occur only when there is a virtual funciton 
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
        void add(double a , double b ) 
        {
            cout<<"Base class Add function " <<a+b << "\n";          
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
        ~B()
        {
            cout<<"@ B class destructor " << this <<"\n";
        }
};

int main()
{
    B object;
    // object.add(10,20);  // this should automatically call the base class function but it is not 
    object.add(10.23,20.12);

    object.A::add(10.23,20.12);
}