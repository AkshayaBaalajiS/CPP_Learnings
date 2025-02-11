#include<iostream>
using namespace std ;

int main()
{
    // the below cant be done because the if the variable is created as const we cant asssign for that variabe 
    // const int a ;
    // a=100;

    // const variable should be initialized not assigned 
    const int a =100 ;

    // a=123 // error 
    // for changing the value we have to create a const int * based on the value we access  
    const int * ptr ;
    ptr=&a;
    cout << "A = " << a <<endl;
    cout << "*ptr = " << *ptr <<endl;

    cout<<"After changing value ....\n";
    
    int * ptr_1=const_cast<int *>(ptr);
    *ptr_1 = 213;

    cout << "A = " << a <<endl;
    cout << "*ptr = " << *ptr <<endl;
    cout<<"*ptr_1  = " << *ptr_1 <<endl;
}