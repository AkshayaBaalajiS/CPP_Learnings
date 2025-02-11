#include<iostream>
using namespace std;

class sampleClass
{
    public :
        sampleClass()
        {
            cout<<"sampleClass constructor called ..\n";
        }
};
/*
This is the difference the class is having the constructor through the public and the structor is calling the constructor without public 
structure is always public 

class members are private scope 
structure members are public scope 
*/

struct sampleStructure 
{
    sampleStructure()
    {
        cout<<"sampleStructure constructor called ..\n";
    }

};
int main()
{
    cout<<"This is the program to understand the difference between class and structure ..\n";
    
    sampleClass object ;

    sampleStructure object_1;


}