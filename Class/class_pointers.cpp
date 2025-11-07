#include<iostream>

using namespace std;

class baseClass
{
    public :
        baseClass()
        {
            cout<<"baseClass constructor called ..\n";
        }

        virtual void function_to_do_something()
        {
            cout<<"Base Class virtual void function_to_do_something()..\n";
        }

        virtual ~baseClass()
        {
            cout<<"baseClass destructor called ..\n";
        }
};

class derivedClass : public baseClass
{
    public :
        derivedClass()
        {
            cout<<"derivedClass constructor called ..\n";
        }

        virtual void function_to_do_something()
        {
            cout<<"Derived Class virtual void function_to_do_something()..\n";
        }

        ~derivedClass()
        {
            cout<<"derivedClass destructor called ..\n";
        }
};


int main()
{
    cout<<"This is a program to understand how the base class access derived class function because of virtual and assigning base class pointer with derived class ..\n";

    cout<<"=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\n";
    baseClass * ptr = new baseClass();
    ptr->function_to_do_something();
    cout<<"=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\n";
    baseClass * ptr_1 = new derivedClass();
    ptr_1->function_to_do_something();
    cout<<"=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\n";
    delete ptr;
    cout<<"=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\n";
    delete ptr_1; // this is the use of virtual on destructor of the baseclass here rthe derived class destructor also called 
    cout<<"=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\n";


    
}