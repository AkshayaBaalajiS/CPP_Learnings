#include<iostream>
using namespace std;

class Interface
{
    public : 
        Interface()
        {
            cout<<"Interface Constructor Called \n";
        }
        virtual void function_to_do_something() = 0;
        virtual void function_to_do_something_1() = 0;
        virtual void function_to_do_something_2() = 0;
        // Interface is a class with only pure virtual function 

};

class childClass1 : public Interface
{
    public :
        childClass1()
        {
            cout<<"ChildClass constructor called \n";
        }

        void function_to_do_something() override
        {
            cout<<"This is the Interface function (function_to_do_something_()) overrided in the derived class \n";
        }

        void function_to_do_something_1() override
        {
            cout<<"This is the Interface function (function_to_do_something_1()) overrided in the derived class \n";
        }

        void function_to_do_something_2() override
        {
            cout<<"This is the Interface function (function_to_do_something_2()) overrided in the derived class \n";
        }
};


int main()
{
    cout<<"This is the program to understand the Abstract Class and Pure Virtual Function in c++ \n";

    // Interface iobject ; //  in Interface the object cant be created (error : Unimplemented pure virtual method in 'baseClass' ) 
    childClass1 object ;
    object.function_to_do_something();
    object.function_to_do_something_1();
    object.function_to_do_something_2();
    
}
