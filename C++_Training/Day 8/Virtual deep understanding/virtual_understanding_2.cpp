#include <iostream>
using namespace std;
 
namespace group1
{
    struct Base
    {
        void mfun() { vfun(); }
        virtual void vfun() { cout<<"Base:vfun:\n"; }  // virtual not to bind at compile time 
        /*
        
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
        dObj.mfun();
        cout<<"---------------\n";
        dObj.vfun();
        cout<<"---------------\n";
        
        
        cout<<"****************\n";
        cout<<"****************\n";
        Base object ;  
        object.mfun(); // Base:vfun is printed it is of type Base 

        // runtime binding :
        
    }
}
 
int main()
{
    group1::main();
}