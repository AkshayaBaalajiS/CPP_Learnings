#include <iostream>
using namespace std;

int main()
{
    printf("Hello World");
    int a=10,b=20,c=30;
    const int *p = &a ;
    int const *q = &b ;
    int* const r = &c ;
    
    cout<<"Address of variables are \n";
    cout<<"THe address of a " << &a <<"\n";
    cout<<"THe address of b " << &b <<"\n";
    cout<<"THe address of c " << &c <<"\n";
    
    cout <<"The address of the variable by pointers \n";
    cout <<"The address of the pointers p  "<< p << "\n";
    cout <<"The address of the pointers q  "<< q << "\n";
    cout <<"The address of the pointers r  "<< r << "\n";
    // cout <<"The address of the variable by pointers \n";
    
    cout<<"Try changing the address of the pointers \n" ;
    p = p+2 ;
    cout <<"The address of the pointers p after p = p+2  "<< p << "\n";
    p = &b ;
    cout <<"The address of the pointers p  p = &b "<< p << "\n";

    //The below action is not possible for the declaration 
    // *p =23;
    // cout<<"The value of the pointer p modified " << *p << "\n";
    
    q = q+2 ;
    cout <<"The address of the pointers q after q = q+2  "<< q << "\n";
    q = &a ;
    cout <<"The address of the pointers q  q = &a "<< q << "\n";

    //The below declaration is not possible for the below const 
    // *q =23;
    // cout<<"The value of the pointer q modified " << *q << "\n";
    
    // int* const r = &c ; for this declaraTION THE BELOW IS NOT POSSIBLE
    // r = r+2 ;
    // cout <<"The address of the pointers r after r = r+2  "<< r << "\n";
    // r = &b ;
    // cout <<"The address of the pointers r  r = &b "<< r << "\n";
    //THe belo action can be done for the pointer 
    *r =23;
    cout<<"The value of the pointer r modified " << *r << "\n"; 
    
    

    return 0;
}
