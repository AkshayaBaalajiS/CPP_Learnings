#include<iostream>
#include <cstdarg>

using namespace std;

void elipsesFunction(int n , ...)
{
    cout<<"This is a elipsesFunction  .....\n";
    va_list elipsesArg ;
    va_start(elipsesArg,n);
    
    cout<<"Argument passed are  : " ;
    for(int i=0;i<n;i++)
    {
        int number = va_arg(elipsesArg,int);
        cout<< number << " ";
    }
    cout<<"\n";
}

int main()
{
    cout<<"This program is to understand how to work on the variable number of arguments ...\n";
    elipsesFunction(1,2);
    
    elipsesFunction(4,1,2,3,4);
    
    elipsesFunction(2,1,2);
    
    elipsesFunction(6,1,2,3,4,5,6);
    
}