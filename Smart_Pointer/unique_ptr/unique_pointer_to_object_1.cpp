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
    
    // sampleClass object(12,45.4554);

    // the below cant be done because the new will give the mem location and the instance that cant be assigned with pointer 
    sampleClass object = new sampleClass(12,45.4554);

    unique_ptr<sampleClass> ptr (object); // error 

    

}
