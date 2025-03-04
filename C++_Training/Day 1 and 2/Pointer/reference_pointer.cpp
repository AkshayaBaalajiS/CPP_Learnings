#include<iostream>
using namespace std ;

int main()
{
    int i=10 ; 

     //*p is the alias of the variable i 
    //Address of operator (C++ Reference pointer )
    int & pointer = i ; // int * const p = &i ;
    cout << "Checking Values :\n";
    cout << "&pointer : " << &pointer << " Value : " << (pointer) << " address it hold  : " << (pointer)<< " Address of i " << &i  << " i : " << i; 
    // here we cant get the address of the pointer variable C++ abstract one level down 

    pointer =23;
    cout << "\n&pointer : " << &pointer << " Value : " << (pointer) << " address it hold  : " << (pointer)<< " Address of i " << &i  << " i : " << i; 
    // here we cant get the address of the pointer variable C++ abstract one level down 
}