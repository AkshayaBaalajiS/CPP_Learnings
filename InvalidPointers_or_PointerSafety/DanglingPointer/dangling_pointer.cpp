#include<iostream>
using namespace std ;

int main()
{
    cout<<"This is a program to understand the dangling pointer \n";

    int * ptr = new int ;
    *ptr = 100 ;

    // here we a re initilizing 
    // int * var = ptr;

    // here we are assigning address  
    // int * var ;
    // var= ptr;
    // cout << "* var  = " << *var ;


    // here we are assigning value  
    // the below is on error (seg fault) because the var location is not found (it points to no where are we are dereferencing it that is dangling pointer points to no where )
    // int * var ;
    // *var= *ptr;
    // cout << "* var  = " << *var ;

    // the below no error because the var points to the location where the ptr points (so when dereferncing it there wont be any error)
    int * var ;
    var = ptr;
    *var= *ptr;
    cout << "* var  = " << *var <<endl;


    // the below I will do the same as above but I will use new 
    int *var_1= new int;
    *var_1=*ptr; 


    cout << "* var  = " << *var <<endl;

    // simple dangling point not like above 
    int * ptr_3 = new int ;
    *ptr_3=123;

    int *var_2 = ptr_3;

    // now there wont be any error 
    cout<<"* var_2 = " << *var_2<<endl;

    // we are creating error by deleting the pointer 
    delete ptr_3;

    // NOw the error comes 
    cout<<"* var_2 = " << *var_2<<endl;
    /* this is because previously it is pointing to some memory location and dereferencing it 
    but now that location is deleted and it points to no where now and while dereferencing error occurs or garbage value will come 
    */
}