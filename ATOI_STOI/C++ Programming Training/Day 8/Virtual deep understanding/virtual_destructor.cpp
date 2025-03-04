#include<iostream>
using namespace std ;
namespace group1
{
    struct Base
    {
        Base()
        {
            cout << "Base::Base\n";
        }
        virtual ~Base()
        {
            cout << "Base::~Base\n";
        }
    };
    struct Derived : Base
    {
        Derived()
        {
            cout << "Derived::Derived\n";
        }
        ~Derived()
        {
            cout << "Derived::~Derived\n";
        }
    };

    void main()
    
    {
        Base * bp = NULL;
        
        
        bp = new Derived();// virtual is needee here for enterring into the destructor of the derived class
        //in the above the the object is of the Base type it will only call only its destructor  
        // Derived * bp = new Derived();// this derived object so it will word normally
        cout << "_----------------------------------\n";
        delete bp;
        // bp-> ~ base ()
        cout << "-----------------------------------------\n";
    }
    
}
int main()
{   
    group1::main();
}