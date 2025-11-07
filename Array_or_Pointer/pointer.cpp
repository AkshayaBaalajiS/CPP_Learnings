#include<iostream>
using namespace std;

int main()
{
    float fvariable = 12.232; 
    cout<<"The float variable = " << fvariable << endl;
    
    float * fptr =  &fvariable;
    cout<<"The *fptr is pointer =  " << *fptr <<endl ;
    cout<<"The float variable = " << fvariable << endl;

    *fptr = 34.232 ;
    cout<<"The *fptr is pointer =  " << *fptr <<endl ;
    cout<<"The float variable = " << fvariable << endl;

    // checking the float to int * pointer 
    // int * ptr = &fvariable;  // a value of type "float *" cannot be used to initialize an entity of type "int *"
}