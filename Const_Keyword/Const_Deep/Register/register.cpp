#include<iostream>
using namespace std ;

int main()
{
    cout<<"This is the program to understand the register keyword ...\n";
    register int ivariable = 123;
    /*
    Register is a form of hint to the compiler that the variable will be 
    accessed heavily and it need to be stored on the CPU register 
    */
    cout<<"Thre address of the register variable is : " << &ivariable <<"\n";

}