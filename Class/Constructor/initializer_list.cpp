#include<iostream>
using namespace std;

class sampleClass
{
    int iVariable;
    float fVariable;
    char cVariable;
    public:
        // even if we give on any order the order of initialization will be from the order of declaration 
        sampleClass(): fVariable(1.11), cVariable('r'), iVariable(2)
        {
            cout<<"The constructor of sampleClass called \n ";
        }

        ~sampleClass()
        {
            cout<<"The Destructor of sampleClass called \n ";
            cout<<"iVariable = " << iVariable <<  "  fvariable = " << fVariable << "  cVariable = " << cVariable << endl ;
        }
};


int main()
{
    cout<<"This is a program for understanding the initializer list of a class ..\n";
    sampleClass object;
}