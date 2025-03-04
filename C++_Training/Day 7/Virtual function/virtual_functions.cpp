#include<iostream>
using namespace std ;
/*
Any class with one virtual function that is polymorphic class 
*/
class A 
{
    // int private_variable;
    public:
        //void * m_vptr ; // 8 bytes 
        virtual void function()
        {
            cout<<"Base class function\n" ;
        }
        
        virtual void function_1()
        {
            cout<<"Base class function 1 \n";
        }

        void function_2()
        {
            cout<<"Base class function 2 \n";
        }
};

class B : public A 
{
    // int private_variable_1;
    public:
        void function() override
        {
            cout<<"Derived class function\n";
        }

        //in base class the function_1 is virtual and automatically the control comes here without override 
        void function_1() 
        {
            cout<<"Derived class function 1 \n";
        }

        void function_2()
        {
            cout<<"Derived class function 2 \n";
        }
};

void size_of_class()
{
    cout<<"The sizeof class A = " << sizeof(A) <<"\n";
    cout<<"The sizeof class B = " << sizeof(B) <<"\n";
    
}

int main()
{
    size_of_class();
    /*
    Due to virtual keyword in base class a pointer will be created in base class so the size will be 8 and 8 
    */

    A base_object;
    B derived_object;

    A * ptr = &derived_object ; 
    ptr-> function();
    // call A::function 
    A &ref_ptr = derived_object ;
    ref_ptr.function();
    // call A::function 

    ref_ptr.function_1();
    ptr->function_1();

    ref_ptr.function_2();
    ptr->function_2();
    
}