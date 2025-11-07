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
    cout<<"This is a program to understand the unique_ptr problems\n";

    // one pointer to the class 
    sampleClass * class_ptr = new sampleClass(12,3435.4545);

    unique_ptr<sampleClass> uptr (class_ptr);
    
    // on one pointer only one unique_ptr can access 
    // unique_ptr<sampleClass> uptr_1 (class_ptr);  // code will compile by the code dump will happen 


    sampleClass * class_ptr_1 = class_ptr;

}