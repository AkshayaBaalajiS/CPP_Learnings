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
    cout<<"This is a program to understand reference count on shared_ptr \n";

    // way 1
    shared_ptr<sampleClass> shr_ptr (new sampleClass(34,45.56567));

    // way 2
    shared_ptr<sampleClass>shr_ptr_1;
    shr_ptr_1 = shr_ptr;   

    // way 3 // this is the proof the shared ptr can hold multile times same pointer (address)
    shared_ptr<sampleClass> shr_ptr_2 ;
    shr_ptr_2=shr_ptr;
    

    // counting the reference using in this prg 
    cout<<"Reference COunt of the shared ptr 1  = " << shr_ptr.use_count()<<std::endl;

    cout<<"Reference COunt of the shared ptr 2  = " << shr_ptr_1.use_count()<<std::endl;

    cout<<"Reference COunt of the shared ptr 3  = " << shr_ptr_2.use_count()<<std::endl;
    
}