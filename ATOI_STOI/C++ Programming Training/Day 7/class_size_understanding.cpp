#include<iostream>
using namespace std ;

class A 
{
    // int private_variable;
    public:
        void function()
        {
            cout<<"Base class function\n" ;
        }
};

class B : public A 
{
    // int private_variable_1;
    public:
        void function()
        {
            cout<<"Base class function\n";
        }
};

void size_of_class()
{
    cout<<"The sizeof class A = " << sizeof(A) <<"\n";
    cout<<"The sizeof class B = " << sizeof(B) <<"\n";
    
}

int main()
{
    size_of_class();
}