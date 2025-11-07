#include<iostream>
#include <ostream>
using namespace std;

class SampleClass
{
    public :
        SampleClass()
        {
            cout<<"SampleClass constructor called \n";
        }
        friend ostream & operator << (ostream & oref , SampleClass & ref );

};
ostream &  operator << (ostream & oref , SampleClass & ref )
{
    oref<<"This is the SampleClass object\n";
    return oref ;
}
int main()
{
    cout<<"This is the function to print the object of the class \n";

    SampleClass object;
    cout<<object;
}