#ifdef CPP
#include <iostream>
#endif

using namespace std;

int main()
{
    cout<<"This is the program to understand the shallow copy in c++\n";
    int a= 10;
    int * ptr = &a;

    int * ptr_1 = ptr ;
    *ptr_1 = 23;
    
    cout<<"*ptr_1  = " << *ptr_1 <<endl;
    cout<<"*ptr = " << *ptr <<endl;
    cout<<"a = " <<a <<endl;

}

/*
What is shallow copy :
    When 2 Pointer pointing to the same memory location any changes made on one 
    affect the other is known as shallow copy   
*/