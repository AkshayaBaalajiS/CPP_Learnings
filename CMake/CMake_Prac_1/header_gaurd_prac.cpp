#ifdef HEADER
#include<iostream>
#endif

#ifndef HEADER
#define HEAEDER
#include<iostream>
#endif

using namespace std;

int main()
{
    cout<<"This is the program to understand the Header Guard working\n";
#ifdef PRINT
    cout<<"The print Macro is defined \n";
#else
    cout<<"The print Macro is not defined\n";
#endif

}   