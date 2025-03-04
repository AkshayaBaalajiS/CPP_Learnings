#include <iostream>
using namespace std;
 
namespace group1
{
    struct A
    {
        A() /*vptr(A::vtable)*/ { vfun();}
        virtual void vfun() { cout<<"A:vfun:\n"; } // by the golden rule it wont know about the derived class member function 
        ~A() {vfun();}
    };
 
    struct B : A
    {
        B() /* this(A), vptr(B::vtable)*/{vfun();}
        // here the virtual will be written by the compailer at compile time 
        // We have ingherited from base and it have same name and signature 
        void vfun() /*A(this) */  { cout<<"B:vfun:\n"; }// by the golden rule it wont know about the derived class member function 
        ~B() {vfun();}    // ~A()
    };
 
    void main()
    {
        B object;
        cout<<"---------------------------\n";
    }
}
 
int main()
{
    group1::main();
}