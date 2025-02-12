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
    
    // new will give the address of the object created in the heap segment 
    // (object will be created frmo the constructor call)
    // this is the reason the below cant be done 
    // sampleClass object = new sampleClass(12,45.4554);
    
    sampleClass * ptr = new sampleClass(12,45.4554);


}
