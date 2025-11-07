#include<iostream>
using namespace std;

class SingleTon
{
    private : 
        int iVar ;
        SingleTon() :  iVar(103)
        {
            cout<<"This is a SingleTon Class constructor \n";
        }
        ~SingleTon()
        {
            cout<<"This is a SingleTon Class Destructor \n";
        }
    public :
        static SingleTon * ptr ;
        static void objectCreation()
        {
            ptr = new SingleTon();
        }

        void function_to_do_something()
        {
            cout<<"This is a function to print something \n";
            cout<<"Private data member Value  :  " << iVar<<endl;
            delete ptr;
        }      
};    
SingleTon * SingleTon::ptr = nullptr;   

int main()
{
    // SingleTon object; // this will create error because we have a private constructor and destructor so making the constructor call inside the class make no error 
    SingleTon::objectCreation();
    SingleTon::ptr->function_to_do_something();

}    