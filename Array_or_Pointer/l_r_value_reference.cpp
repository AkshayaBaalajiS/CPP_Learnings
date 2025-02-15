#include<iostream>
using namespace std ;

int main()
{
    cout<<"This is the reference understanding\n";
    int ivar = 10 ;

    // int & ref_1 ; // this cant be done because there is no object to bind to it 
    
    // lvalue reference 
    int & lref = ivar; // this is the way to assign the value to reference  
    cout<<"This is the value of the lvalue reference  : " << lref<<endl;


    // rvalue reference can be applied on the temporary values that will not live long  
    // int &&rref = ivar; // this cant be done 
    int && rref = 12;
    cout<<"This is the value of the rvalue reference  : " << rref<<endl;
}