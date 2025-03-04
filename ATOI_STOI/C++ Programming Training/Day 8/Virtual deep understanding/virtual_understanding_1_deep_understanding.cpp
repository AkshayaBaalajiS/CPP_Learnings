#include <iostream>
using namespace std;
 
namespace group1
{
    struct A
    {
        A() /*   *vptr (Base::vtable )      Base::vfun*/ { vfun();}
        virtual void vfun() { cout<<"A:vfun:\n"; }   // dynamic binding / runtime binding 
        //Due to the golden rule (base know nothing about the derived )
        /*
            Derefer the bp to reach the vptr in object 
            derefer vptrr to reach the corresponding vtable 
            Add offset in vtable to reach ::vfun() index / address 
            Derefer to fetch member fucntion on that address 
            PAsss argument and make a class 
        */
        ~A() /*  *vptr (Base::vtable )*/ {vfun();}
    };
 
    struct B : A
    {
        B() /* base(this)    * vptr (Derived::vtable )*/ {vfun();}
        void vfun() /*A(this) */  { cout<<"B:vfun:\n"; }
        ~B() /* ~base(this)    * vptr (Derived::vtable )*/{vfun();}    // ~A()
    };
 
    void main()
    {
        B object;
        /*
        Derived constructor class 
        From Derived constructor the Base constructor called

        */
        cout<<"---------------------------\n";
    }
}
 
int main()
{
    group1::main();
}

