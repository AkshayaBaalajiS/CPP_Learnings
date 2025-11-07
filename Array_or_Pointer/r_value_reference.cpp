#include<iostream>

using namespace std;

void lvalue_ref_function(int & ref )
{
    cout<<"++++++++++++++++++++++++++++++++++++++++++++\n";
    cout<< "void lvalue_ref_function(int & ref )....\n";
    cout<<"The value is  : " << ref <<"\n";
    cout<<"++++++++++++++++++++++++++++++++++++++++++++\n";

}

void rvalue_ref_function(int && ref )
{
    cout<<"++++++++++++++++++++++++++++++++++++++++++++\n";
    cout<< "void rvalue_ref_function(int & ref )....\n";
    cout<<"The value is  : " << ref <<"\n";
    cout<<"++++++++++++++++++++++++++++++++++++++++++++\n";
}



int main()
{
    cout<<"This is the program to understand the r value reference \n";
    
    int local_variable = 10 ;

    // rvalue_ref_function(local_variable); // this will give error because that is expecting a rvalue which will expect only temporary variable 
    // lvalue_ref_function(10);  // this will give error because that is expecting a lvalue which is expecting only the variable which address can be fetched 

    lvalue_ref_function(local_variable);
    rvalue_ref_function(10);
    

    int * ptr;
    ptr = &local_variable;

    lvalue_ref_function(*ptr);
    rvalue_ref_function(move(*ptr));
    rvalue_ref_function(move(local_variable));
    
    

}