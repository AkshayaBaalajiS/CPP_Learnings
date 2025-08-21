#include<iostream>
using namespace std;

void function_to_do_something(int a, int b)
{
    cout<<"void function_to_do_something(int a, int b)...\n";
}


void function_to_do_something(char a, char b)
{
    cout<<"void function_to_do_something(char a, char b)...\n";
}


void function_to_do_something(char a, char b, char c)
{
    cout<<"void function_to_do_something(char a, char b, char c )...\n";
}

// Here this will create a ambiguity 
// void function_to_do_something(char a, char b, char c)
// {
//     cout<<"void function_to_do_something(char a, char b, char c )...\n";
// }


// Ambiguous 
// void function_to_do_something(const int a )
// {
//     cout<<"void function_to_do_something(const int a )...\n";
// }


void function_to_do_something(int a )
{
    cout<<"void function_to_do_something(int a )...\n";
}

void function_to_do_something(int * ptr)
{
    cout<<"void function_to_do_something(int * ptr)...\n";
}


// This will create ambiguous 
// void function_to_do_something(int & ref )
// {
//     cout<<"void function_to_do_something(int & ref )...\n";
// }



int main()
{
    cout<<"This is a program to understand the static / compile time / function overloading \n";
    int iVar = 10;
    int iVar_1 = 10;
    
    char cVar = 'd';
    char cVar_1 = 'e';
    char cVar_2 = 'e';
    
    
    function_to_do_something(iVar,iVar_1);
    function_to_do_something(cVar,cVar_1);
    function_to_do_something(cVar,cVar_1,cVar_2);

    int *ptr =&iVar;
    int & ref = iVar_1;

    function_to_do_something(*ptr);

    function_to_do_something(ptr);

    function_to_do_something(ref);
    
    function_to_do_something(iVar);   
    
}