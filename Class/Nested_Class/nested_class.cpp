#include<iostream>
using namespace std;

class baseClass
{
    int iPrivateVariable ;
    float fPrivateVariable ;
    public :
        class nestedClass
        {
            public:
                int iPublicVariable ;
                float fPublicVariable;
                nestedClass()
                {
                    cout<<"Constructor of the nestedClass called ..\n";
                }
                void function_to_do_something()
                {   
                    cout<<"Derived class function to do something ..\n";
                }

        };
        nestedClass * nPtr;
        baseClass()
        {
            cout<<"Constructor of the baseClass called ..\n";
        }
        

};


int main()
{
    cout<<"This is the program to understand how the nested class works ..\n";
    baseClass object;
    object.nPtr = new baseClass::nestedClass();
    object.nPtr->function_to_do_something();
    cout<<"Derived class data member  : " << object.nPtr->fPublicVariable << endl;
}
