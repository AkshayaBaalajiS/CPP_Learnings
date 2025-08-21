#include<iostream>
using namespace std ;


/*
This is the program that demonstrate putting the inline function cant be worked like macro 
*/

inline int simple_inline_function(int a)
{
    return a + 100 ;
}

inline void function_to_do_something(int a)
{
    cout<<"This is the function to print the argument passed  \n"<<"Args = " << a <<"\n";
}

inline void function_to_do_something_2(int &a)
{
  a=1233;   
}

void function_to_do_something_1(int a)
{
    cout<<"This is the normal function to print the argument passed  \n"<<"Args = " << a <<"\n";
}


int main()
{
    cout<<"This is a program for understainding inline function and proving the inline wont work like macro function  ...\n";
    int a =100;
    function_to_do_something(a);
    function_to_do_something_2(a);

    function_to_do_something_1(a);
    cout<<"This is the value of the A  = " << a <<"\n";

    int sum = simple_inline_function(a);
    cout<<"This is the simple inlined function  " << sum<<endl;
}
