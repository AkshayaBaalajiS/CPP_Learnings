#include<iostream>
using namespace std;

template <typename t1>
void function_to_do_something(t1 arg1 , t1 arg2)
{
    cout<<"This is the function_to_do_something(t1 arg1 , t1 arg2)  \n"; 
    cout<<"The arguments are  : Arg1  = " << arg1 << "   Arg2 = " << arg2 ;
    cout<<"\n";
}

template <typename t1, typename t2>
void function_to_do_something(t1 arg1 , t2 arg2)
{
    cout<<"This is the void function_to_do_something(t1 arg1 , t2 arg2) \n";
    cout<<"The arguments are  : Arg1  = " << arg1 << "   Arg2 = " << arg2 ;
    cout<<"\n";
}

void function_to_do_something(int arg1 , int arg2)
{
    cout<<"This is the void function_to_do_something(int arg1 , int arg2)  \n"; 
    cout<<"The arguments are  : Arg1  = " << arg1 << "   Arg2 = " << arg2 ;
    cout<<"\n";
}


void function_to_do_something(char arg1 , char arg2)
{
    cout<<"This is the void function_to_do_something(char arg1 , char arg2)  \n"; 
    cout<<"The arguments are  : Arg1  = " << arg1 << "   Arg2 = " << arg2 ;
    cout<<"\n";
}
int main()
{
    cout<<"This is a program to understand the function overloading ....\n";

    // this is the way to call the function with template and type as int
    function_to_do_something<int>(12.23,14.23);
    cout<<"-----------------------------------------------------------\n";

    // this is the way to call the function with template and type as float  
    function_to_do_something<double>(12.1,14.2);
    cout<<"-----------------------------------------------------------\n";


    function_to_do_something(12,14);
    cout<<"-----------------------------------------------------------\n";

    function_to_do_something('c','d');
    cout<<"-----------------------------------------------------------\n";    

    function_to_do_something<float, char>(24.23,'d');
    cout<<"-----------------------------------------------------------\n";    

    //this is to check the wrong type 
    function_to_do_something<char, char>(24.23,'d');
    cout<<"-----------------------------------------------------------\n";    

}