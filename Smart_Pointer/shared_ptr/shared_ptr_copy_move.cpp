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
    cout<<"This is a program to understand the ways of initialization and copy and move on shared_ptr \n";

    // way 1
    shared_ptr<sampleClass> shr_ptr (new sampleClass(34,45.56567));

    sampleClass * ptr  = new sampleClass(12,4556675.5665);

    // way 2
    shared_ptr<sampleClass>shr_ptr_1(ptr);   

    // way 3 // this is the proof the shared ptr can hold multile times same pointer (address)
    shared_ptr<sampleClass> shr_ptr_2 (ptr);
    
    // copy and move 
    
    // way 3 // this is the proof the shared ptr can hold multile times same pointer (address)
    shared_ptr<sampleClass> shr_ptr_3 (std::move(shr_ptr_2));
    
    // way 4 // copy is done and this is the proof the shared ptr can hold multile times same pointer (address)
    shared_ptr<sampleClass> shr_ptr_4 (ptr);
    
    // way 5 // direct copy 
    shared_ptr<sampleClass> shr_ptr_5 ;
    shr_ptr_5 = shr_ptr_4;

    shared_ptr<sampleClass> shr_ptr_6 ;
    shr_ptr_6 = shr_ptr_4;


    // counting the reference using in this prg 
    cout<<"Reference COunt of the shared ptr 1  = " << shr_ptr.use_count()<<std::endl;

    cout<<"Reference COunt of the shared ptr 2  = " << shr_ptr_1.use_count()<<std::endl;

    cout<<"Reference COunt of the shared ptr 3  = " << shr_ptr_2.use_count()<<std::endl;

    cout<<"Reference COunt of the shared ptr 4  = " << shr_ptr_3.use_count()<<std::endl;

    cout<<"Reference COunt of the shared ptr 5  = " << shr_ptr_4.use_count()<<std::endl;

    cout<<"Reference COunt of the shared ptr 6  = " << shr_ptr_5.use_count()<<std::endl;

    cout<<"Reference COunt of the shared ptr 7  = " << shr_ptr_6.use_count()<<std::endl;

    
    
    
    // this is the proof the shared ptr cant hold another shared pointer
    // shared_ptr<shared_ptr<sampleClass>> shr_ptr_4 (shr_ptr_3);
    
    
}