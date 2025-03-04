#include <iostream>
using namespace std ;
class A 
{
    public :
        virtual void function()
        {
            cout<<"A function ";
        }
};
class B : public A
{
    public :
        void function()
        {
            cout<<"B function ";
        }
};
int main()
{
    A * ptr = new A ();
    ptr->function();// afun
    B * b_ptr = new B();
    b_ptr->function();//b
    
    A a_object;
    B b_object;
    
    
    A * a_ptr = &b_object;
    a_ptr->function();//b
    
    
    A * aa_ptr= &b_object;
    aa_ptr->A::function();//a
}