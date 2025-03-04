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
    // A * object_aa = object_d ; // it creates error  
    A * object_aa = dynamic_cast <A *>(&object_d) ; 
}
