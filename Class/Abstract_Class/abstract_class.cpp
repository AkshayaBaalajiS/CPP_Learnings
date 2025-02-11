#include<iostream>
using namespace std;

class baseClass
{
    public : 
        baseClass()
        {
            cout<<"baseClass Constructor Called \n";
        }
        virtual void function_to_do_something() = 0;
        virtual void function_to_do_something_1() = 0;
        virtual void function_to_do_something_2() = 0;

        // error Unimplemented pure virtual method 'function_to_do_something' in 'baseClass'
        // proof that for abstract class the object cant be created even if it has the function definition for one function and others pure virtual function 
        void function_simply()
        {
            cout<<"This is the baseCLass function \n";
        }
};
class childClass1 : public baseClass
{
    public :
        childClass1()
        {
            cout<<"ChildClass constructor called \n";
        }

        void function_to_do_something() override
        {
            cout<<"This is the baseClass function (function_to_do_something_()) overrided in the derived class \n";
        }

        void function_to_do_something_1() override
        {
            cout<<"This is the baseClass function (function_to_do_something_1()) overrided in the derived class \n";
        }

        void function_to_do_something_2() override
        {
            cout<<"This is the baseClass function (function_to_do_something_2()) overrided in the derived class \n";
        }
};


int main()
{
    cout<<"This is the program to understand the Abstract Class and Pure Virtual Function in c++ \n";

    // baseClass object ; //  in abstract class the object cant be created (error : Unimplemented pure virtual method in 'baseClass' ) 
    childClass1 object ;
    object.function_to_do_something();
    object.function_to_do_something_1();
    object.function_to_do_something_2();
    object.function_simply();
    
}
