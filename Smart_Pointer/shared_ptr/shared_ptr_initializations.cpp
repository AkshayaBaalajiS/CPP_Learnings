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
    cout<<"This is a program to understand the ways of initialization \n";

    // way 1
    shared_ptr<sampleClass> sam_ptr (new sampleClass(34,45.56567));

    sampleClass * ptr  = new sampleClass(12,4556675.5665);

    // way 2
    shared_ptr<sampleClass>sample_ptr_1(ptr);   

    
}