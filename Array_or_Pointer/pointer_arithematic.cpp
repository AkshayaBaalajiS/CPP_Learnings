#include<iostream>
using namespace std;

int main()
{
    cout<<"This is the program to understand the pointer arithametics \n";
    int arr[] = {10,20,30,40,50,60,7};
    
    int * ptr ;
    ptr = arr;

    cout<<"*(ptr++) = " <<*(ptr++) << endl ;
    cout<<"*(++ptr) = " <<*(++ptr) << endl ;
    
    cout<<"*ptr++ = " <<*ptr++ << endl ;   // this works like *(ptr=ptr+1)
    cout<<"*++ptr = " <<*++ptr << endl ;

    cout<<"*ptr+1 = " <<*ptr+1 << endl ;
    cout<<"1+*ptr = " <<1+*ptr << endl ;
    

}

// do a diagram for that for understanding 