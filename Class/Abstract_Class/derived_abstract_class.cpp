#include<iostream>
using namespace std;


class baseClass 
{
    public :
        baseClass()
        {
            cout<<"BaseCLass constructor called \n";
        }

        void function_to_do_something() 
        {
            cout<<"This is the baseClass function (function_to_do_something_()) \n";
        }

        void function_to_do_something_1()
        {
            cout<<"This is the baseClass function (function_to_do_something_1()) \n";
        }

        void function_to_do_something_2()
        {
            cout<<"This is the baseClass function (function_to_do_something_2()) \n";
        }

        void baseclass_function()
        {
            cout<<"This is the baseClass function (baseclass_function()) \n";
        }
};

class childClass : public baseClass
{
    public : 
        childClass()
        {
            cout<<"childClass Constructor Called \n";
        }
        virtual void function_to_do_something() = 0;
        virtual void function_to_do_something_1() = 0;
        virtual void function_to_do_something_2() = 0;

        // error Unimplemented pure virtual method 'function_to_do_something' in 'childClass'
        // proof that for abstract class the object cant be created even if it has the function definition for one function and others pure virtual function 
        void function_simply()
        {
            cout<<"This is the childClass function \n";
        }
};

class childClass1 : public childClass
{
    public :

        void function_to_do_something() override
        {
            cout<<"This is the childClass function (function_to_do_something_()) overrided in childClass1 \n";
        }

        void function_to_do_something_1() override
        {
            cout<<"This is the childClass function (function_to_do_something_1()) overrided in childClass1 \n";
        }

        void function_to_do_something_2() override
        {
            cout<<"This is the childClass function (function_to_do_something_2()) overrided in childClass1 \n";
        }

};




int main()
{
    cout<<"This is a program to understand the derived abstract class \n ";
    baseClass bObject;
    bObject.function_to_do_something();
    bObject.function_to_do_something_1();
    bObject.function_to_do_something_2();
    
    childClass1 cObject;
    cObject.function_to_do_something();
    cObject.function_to_do_something_1();
    cObject.function_to_do_something_2();
    cObject.baseclass_function();
    cObject.function_simply();
    
    
        
}   