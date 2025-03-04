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
        
        ptr = new A();
        // A() will automatically call the funciton A() inside the class 
        //A() willl only call the constructor not the destructor 
        
        cout <<"ptr holds after new keyword space allocation " << ptr <<"\n";
        
        delete ptr;

        ptr = NULL ;

        //After the delettion the ptr hold the invalid address so assign it to null address to avoid dangling pointer 

        cout <<"ptr holds after delete on ptr : " << ptr <<"\n";
    }
}

int main()
{
    group1::main();
}


