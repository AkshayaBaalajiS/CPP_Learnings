#include<iostream>
using namespace std ;

#define ADD(a,b) a+b

int main()
{
    cout <<"This is the program to demonstrate the macro function and how it is evaluated...\n ";
    
    int a = 12;
    int b = 24;
    cout<< "ADD (A , B) : " << ADD(a,b) << endl;
}