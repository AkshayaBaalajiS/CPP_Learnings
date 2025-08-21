#include<iostream>
using namespace std;

void function_to_do_something(int arg1 , int * arg2 , int & arg3 , int arg4, int &arg5 )
{
    cout<<"++++++++++++++++++++++++++++++++++++++++++++\n";
    cout<<"function_to_do_something(int arg1 , int * arg2 , int & arg3 , int arg4 )\n";
    cout<<"arg1  = " << arg1 << endl;
    cout<<"*arg2  = " << *arg2<< endl;
    cout<<"arg3  = " << arg3 << endl;
    cout<<"arg4  = " << arg3 << endl;

    // by changing the values of * arg2 , arg3 and arg5 we can change the original value 
    cout<<"Changing the values from the function .. \n";
    
    arg5=45;
    cout<<"arg1  = " << arg1 << endl;
    cout<<"*arg2  = " << *arg2<< endl;
    cout<<"arg3  = " << arg3 << endl;
    cout<<"arg4  = " << arg3 << endl;
    
    cout<<"++++++++++++++++++++++++++++++++++++++++++++\n";

}

int main()
{
    cout<<"This is the program to understand how the pointer passed as argument ..\n";
    int a ;

    int * ptr = & a ;

    int & ref = a;

    cout<<"a  = " << a << endl;
    cout<<"*ptr  = " << a << endl;
    cout<<"ref  = " << ref << endl;

    cout<<"-------------------------------------------\n";
    a=12;
    cout<<"a  = " << a << endl;
    cout<<"*ptr  = " << a << endl;
    cout<<"ref  = " << ref << endl;
    
    cout<<"-------------------------------------------\n";
    *ptr=23;
    cout<<"a  = " << a << endl;
    cout<<"*ptr  = " << a << endl;
    cout<<"ref  = " << ref << endl;
    
    cout<<"-------------------------------------------\n";
    ref=34;
    cout<<"a  = " << a << endl;
    cout<<"*ptr  = " << a << endl;
    cout<<"ref  = " << ref << endl;
    
    
    function_to_do_something(a ,ptr , ref , ref , ref);

    cout<<"a  = " << a << endl;
    cout<<"*ptr  = " << a << endl;
    cout<<"ref  = " << ref << endl;
        
    
    
}