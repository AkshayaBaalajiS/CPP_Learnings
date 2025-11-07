#include<iostream>
using namespace std;

int main()
{
    cout<<"This is the program to udnertsand the type casting in c++ \n";
    int a =123;
    
    // widening 
    // short  to int 
    short s = 12;
    int short_to_int = (int)s;  // short type casted to int 
    cout<<"Short to int is : " << short_to_int <<endl;
    
    // char to int 
    char c = 'a';
    int char_to_int = (int)c;
    cout<<"Char to int is : " << char_to_int <<endl;
    
    // narrowing
    // int int_var= -32769;
    // int int_var=  -32768;
    
    // int int_var= 32767;
    int int_var=  32768;
    
    
    
    //  -32,768 to 32,767.
    short int_to_short = (short)int_var;
    cout<<"Int to short is : "<< int_to_short <<endl;
    
    
    char char_var  = 129;
    
    int char_ti_int   =  (int)char_var;
    cout<<"Char to int  is : " << char_ti_int <<endl;
    
}