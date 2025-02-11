#include<iostream>
using namespace std;



class baseClass
{
    public : 
        baseClass()
        {
            cout<<"baseClass Constructor Called \n";
        }
        virtual void function_to_do_something() ;
        virtual void function_to_do_something_1();
        virtual void function_to_do_something_2();

        void function_simply()
        {
            cout<<"This is the baseCLass function \n";
        }

        // this is the proof that the class with no pure virtual function can have the object created 
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

    baseClass bObject ; // this is the proof that the class with no pure virtual function can have object created   
    childClass1 object ;
    object.function_to_do_something();
    object.function_to_do_something_1();
    object.function_to_do_something_2();
    object.function_simply();
    
}
