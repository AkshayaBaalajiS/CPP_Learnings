#include<iostream>
#include <memory>
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
    cout<<"This is a program to understand the smart pointer in c++ \n";

    // unique_ptr<sampleClass> ptr = new sampleClass();
    unique_ptr<sampleClass> ptr(new sampleClass(12,34.454554));

    ptr->function_to_do_something();
    cout<<"Class public int variable  : " << ptr->iVariable <<endl;
    cout<<"Class public float variable  : " << ptr->fVariable <<endl;
    
}