#include <iostream>
using namespace std;

void function_to_do_so()
{
    cout<<"This is the function to do something \n";
}

void function_to_do_so(int a)
{
    cout<<"This is the function to do something that takes int as argument \n";
}

void function_to_do_so(float b)
{
    cout<<"This is the function to do something that takes float as argument \n";
}

void function_to_do_so(char c )
{
    cout<<"This is the function to do something that takes char as arguement\n";
}

void function_to_do_so(double d)
{
    cout<<"This is the function to do something that takes double as argument\n";
}



int main()
{
    cout<<"This is a program to understand how the function overloading happens ..\n";
    function_to_do_so();
    function_to_do_so(12);
    function_to_do_so(23.34);
    function_to_do_so('a');
    function_to_do_so(345.34534);
    
}

/*
For seeing the fucntion decoration do the below 
    g++ -c file.cpp
        file.o will be generated 
    nm file.o > file
        file will be containing the object with only symbols where you can see the decoration 
*/