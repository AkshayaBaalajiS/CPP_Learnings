#include<iostream>
using namespace std ;

class sampleClass
{
    mutable int ivar;
    int ivar_1;
    public :
        sampleClass()
        {
            cout<<"This is the default constructor for the sampleClass ...\n";
        }

        void change_value (int arg) const 
        {
            ivar=arg;
            // ivar_1=arg; // this cant be done because in const function 
        }


        ~sampleClass()
        {
            cout<<"This is the Destructor for sampleClass cleans up the memory..\n";
        }

};
int main()
{
    cout<<"This is the program to understand mutable keyword ..\n";

    // the below is the proof that the mutable can be applied only on the class data members
    // mutable int  ivar ;


}