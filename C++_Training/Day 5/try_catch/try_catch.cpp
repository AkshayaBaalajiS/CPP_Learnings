#include<iostream>
using namespace std ;

namespace group1
{
    class A 
    {
    public :
        A()
        {
            cout<<"@ Constructor \n";
        }
        ~A()
        {
            cout<<"@ Destructor \n";
        }
    };
    void main()
    {
        // A *ptr  ; If = NULL not defined it hold some random address 
        A * ptr = NULL ;
        cout <<"ptr holds " << ptr <<"\n";
        try 
        {
            ptr = new A();
            // A() will automatically call the funciton A() inside the class 
        //A() willl only call the constructor not the destructor 
        }
        catch(bad_alloc errObj)
        {
            cout<<"Bad allocation stratergy  :"  <<" \n";
        }
         cout <<"ptr holds after new keyword space allocation " << ptr <<"\n";
        delete ptr;

    }
}

int main()
{
    group1::main();
}


