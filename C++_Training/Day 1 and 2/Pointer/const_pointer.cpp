#include<iostream>
using namespace std ;

int main()
{
    int i=10 , j=20 ;
// for checking the constant pointer which is changable 
    //Ways it cant be initialized / declared 
    // const int *p = &i;    //the address of the p is changable but we cant modify the value of that address 
    int const *p = &j ;  // this can also be done //the address of the p is changable but we cant modify the value of that address 
    // int *const p  = &i ; //Here the pointer is on const so the address is unmodifyable and the value inside it is modifyable 

 


    int *q = &j ;
    cout << "Checking Values :\n";
    cout << "p : " << p << " i : " << i << " j : " << j  << "\n" ;
    cout << "q : " << p << " i : " << i << " j : " << j  <<"\n";
    cout << "Changing the address hold by the pointer \n" ; 
    //We are checking the const pointer address 
    p = &j ; //this can be done if int const * p = &i or const int *p =&i  
    // *p =120;  // this can be done only is the int *const p = &i 
    q = &i;
    cout << "p : " << p << " i : " << i << " j : " << j  << "\n" ;
    cout << "q : " << p << " i : " << i << " j : " << j  <<"\n";
    cout << "What cant be done in the cont pointer type \n";
    // *p = 12312; // this is invalid
    


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