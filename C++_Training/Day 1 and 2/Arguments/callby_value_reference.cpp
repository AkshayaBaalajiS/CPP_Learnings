#include<iostream>
using namespace std ;

void swap_func(int a , int b )
{   
    cout<<"\nBefore changing :\n";
    cout << "a : " << a << " b : " << b  <<"\n";
    // int temp ;
    // temp =a ;
    // a = b ;
    // b = temp ;
    a ^=b ;
    b ^=a ;
    a ^=b ;
    
    cout<<"After changing :"<<"\n";
    cout << "a : " << a << " b : " << b << "\n ";
    
    /*
      a = 00<7> 0<8> 0<8> 00001010
      b = 00<7> 0<8> 0<8> 00010100
      
      a= a^b ;  00011110 // 30 
      b=b^a ; 00010100 ^ 00011110 =  00001010 // 10 
      a = a^b ; 00001010 ^ 00011110 =  00010100 // 20 
      
    */
   
}

/*
Here I have tried the call by value and tried change the value of the arguments by pointer 
Which wont affect the main function variables 
*/
void swap_in_main(int a , int b ) 
{   
    cout<<"\nBefore changing arguments by pointer  :\n";
    cout << "a : " << a << " b : " << b  <<"\n";
    
    int *p = &a ;
    int *q = &b ;

    int temp;
    temp = *p ;
    *p = *q ;
    *q = temp ; 
    
    cout<<"After changing :"<<"\n";
    cout << "a : " << a << " b : " << b << "\n ";  
}
/*
Below I have done the call be reference method where we will be passing 
the address as argument while calling this function 
*/
void swap_in_main_reference(int *a , int *b )
{   
    cout<<"\nBefore changing by reference :\n";
    cout << "a : " << *a << " b : " << *b  <<"\n";
    int temp;
    temp = *a ;
    *a = *b ;
    *b = temp ; 
    
    cout<<"After changing :"<<"\n";
    cout << "a : " << *a << " b : " << *b << "\n ";
   
}
void swap_in_main_reference_const_Applied(int *const a , int *const b )  //this const pointer will allow to change value not address 
{   
    cout<<"\nBefore changing :\n";
    cout << "a : " << *a << " b : " << *b  <<"\n";
    // int temp ;
    // temp =a ;
    // a = b ;
    // b = temp ;
    *a ^= *b ;
    *b ^=*a ;
    *a ^=*b ;
    
    cout<<"After changing :"<<"\n";
    cout << "a : " << *a << " b : " << *b << "\n ";

    /*
      a = 00<7> 0<8> 0<8> 00001010
      b = 00<7> 0<8> 0<8> 00010100
      
      a= a^b ;  00011110 // 30 
      b=b^a ; 00010100 ^ 00011110 =  00001010 // 10 
      a = a^b ; 00001010 ^ 00011110 =  00010100 // 20 
      
    */
}
int main()
{
    int i=10 , j=20 ;

    swap_func(i,j); // here we are passing by value  
    cout<<"\nAfter Function call done Value of i and j is  :\n";
    cout << "i : " << i  << " j : " << j  <<"\n";

    swap_in_main(i,j); // here we are passing by value and try the pointer to change the value of the argument  
    cout<<"\nAfter Function call done Value of i and j is  :\n";
    cout << "i : " << i  << " j : " << j  <<"\n";

    swap_in_main_reference(&i,&j); // here we are passing by reference 
    cout<<"\nAfter Function call done Value of i and j is  :\n";
    cout << "i : " << i  << " j : " << j  <<"\n";
    
    swap_in_main_reference_const_Applied(&i,&j); // here we are passing by reference 
    cout<<"\nAfter Function call done Value of i and j is  :\n";
    cout << "i : " << i  << " j : " << j  <<"\n";
    
}