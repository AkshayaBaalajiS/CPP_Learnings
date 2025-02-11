#include<iostream>
using namespace std;

class samplelClass
{
    int ivar ;
    float fVar;
    public:
        samplelClass()
        {
            cout<<"This is a constructor for sampleClass .\n";
        }

        void print_function()
        {
            cout<<"Base class void print_function()...\n";
        }

        ~samplelClass()
        {
            cout<<"This is a destructor for sampleClass .\n";
        }
};

class samplelClass_1: public samplelClass
{
    int ivar ;
    float fVar;
    public:
        samplelClass_1()
        {
            cout<<"This is a constructor for sampleClass_1 .\n";
        }

        void print_function()
        {
            cout<<"Derived class void print_function()...\n";
        }

        ~samplelClass_1()
        {
            cout<<"This is a destructor for sampleClass_1 .\n";
        }

};




int main()
{
    cout<<"This is the program to understand the dynamic programming ..\n";

    samplelClass_1 object;

    object.print_function();

}