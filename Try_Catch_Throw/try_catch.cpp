#include<iostream>
using namespace std ;

int main()
{
    cout<<"This is a program to understand Try Catch Throw ..\n";
    int number1;
    int number2;
    cout<<"Enter 2 numbers for performing division..\n";
    cin>> number1;
    cin>> number2;
    int result ;
    try
    {
        if(number2==0)
        {
            throw runtime_error("Zero Division error ");
        }
        result=number1/number2;
    }
    catch (exception & e )
    {
        cout<<"The error occured is : " << e.what() <<"\n";
    }
    
}