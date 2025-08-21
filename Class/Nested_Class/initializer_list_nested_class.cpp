#include<iostream>
using namespace std;

class baseClass
{
    int iPrivateVariable ;
    float fPrivateVariable ;
    public :
        baseClass()
        {
            cout<<"Constructor of the baseClass called ..\n";
        }
        class nestedClass
        {
            public:
                int iPublicVariable ;
                float fPublicVariable;
                nestedClass()
                {
                    cout<<"Constructor of the nestedClass called ..\n";
                }

        };
        nestedClass nObject;

};


int main()
{
    cout<<"This is the program to understand how the nested class works ..\n";
    baseClass object;
}

/*
In this program the nested class constructor called at first before the base class constructor 

this is because the 
    The base constructor called at first and the non static data member initilized which will call the derived class constructor called and at last the constructor body 
*/