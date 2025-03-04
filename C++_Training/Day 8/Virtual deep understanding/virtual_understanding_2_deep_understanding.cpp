#include <iostream>
using namespace std;
 
namespace group1
{
    struct Base
    {
        void mfun() { vfun(); }
        virtual void vfun() { cout<<"Base:vfun:\n"; }  // virtual not to bind at compile time 
        /*
        Understanding :

        */
    };
    struct Derived : Base
    {
        // void mfun() /*Base(this) */  { cout<<"Derived:mfun:\n"; } 
        void vfun() /*Base(this) */  { cout<<"Derived:vfun:\n"; } // when we comment this 
        /*
        derived will search for the vfun in derived class and it is not there so it will go to base class  
        */
    };

    void main()
    {
        Derived dObj;
        cout<<"---------------\n";
        dObj.mfun();
        cout<<"---------------\n";
        dObj.vfun();

        // runtime binding :
        
    }
}
 
int main()
{
    group1::main();
}

/*
default constructor scenarious :
    inheritance : if we not have the destructor in the derived the compiler writes to call the base destructor 
    if we use the virtual fucntion the and the special function is not written the compiler write it to initializa the vptr 



*/
