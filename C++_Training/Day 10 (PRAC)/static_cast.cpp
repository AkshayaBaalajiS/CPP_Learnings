#include<iostream>
using namespace std ;
//Here we are creating a miltilevel inheritance 
struct A {} ;
struct B:A  {} ;
struct C :B {} ;
struct D:C {} ;
int main()
{
    A object_a ;
    B object_b ;
    C object_c; 
    D object_d;
    // D * object_dd = object_a ; // it creates error  
    D * object_aa = static_cast <D *>(&object_a) ; 
}
