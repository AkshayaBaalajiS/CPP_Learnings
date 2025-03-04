#include <iostream>
using namespace std;
 
namespace group1
{
    struct A 
    {
        A()
        {
            cout<<"@ A constructor " << this <<"\n";
        }
        ~A()
        {
            cout<<"@ A Destructor " << this <<"\n";
        }
    };
    struct B : A {
        B() 
        {
            cout<<"@ B Constructor "<<this<<"\n";
        }
        ~B()
        {
            cout<<"@ B Destructor "<<this<<"\n";
        }
    };

    // B object1;  // Globaly stored on data segment 
 
    void main()
    {
        // cout<<"-----------------------\n";
        // B Obj1; //stored as stack object
 
        // A object ;
        cout<<"-----------------------\n";
        A *ap = new B(); // stored as heap ōbject
        
        cout<<"-----------------------\n";
        // ap->~B();
        delete ap;

 
    }
}
   
int main()
{
    group1::main();
}
 