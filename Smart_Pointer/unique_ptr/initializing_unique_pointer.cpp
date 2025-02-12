#include<iostream>
#include<memory>
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
    
    // sampleClass object(12,45.4554); // we cant assign the object to unique_ptr cause it hold only pointer 
    
    sampleClass * class_ptr = new sampleClass(12,45.4554);

    // one way 
    unique_ptr<sampleClass> ptr ( class_ptr);

    // other way
    unique_ptr<sampleClass> ptr_1 ( new sampleClass(56,45.56567));
   

}
