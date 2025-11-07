#include<iostream>
using namespace std;

class sampleClass
{
    public : 
        int iVariable;
        float fVariable ;
        sampleClass(int args1 , float args2) : iVariable(args1) , fVariable(args2)
        {
            cout<<"sampleClass constructor called \n";
        }
        void function_to_do_something()
        {
            cout<<"This is a function from the sampleClass";
        }
        ~sampleClass()
        {
            cout<<"sampleClass destructor called \n";
        }       
};

int main()
{
    cout<<"This is a program to understand the unique pointer initializations \n ";
    
    sampleClass object(12,45.4554);

    unique_ptr<sampleClass> ptr (&object);

}

/*
Reason why this cant be done 
A unique_ptr is designed to manage dynamically allocated objects (usually allocated with new). 
It takes ownership of the pointer, meaning when the unique_ptr is destroyed, it will automatically delete the object it points to.
 */