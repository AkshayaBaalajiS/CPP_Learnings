#include<iostream>
using namespace std ;
int main()
{
    const int a=10 ;
    cout<<"a = " << a <<"\n";
    int *p = const_cast<int *>(&a);
    cout<<"*p = " << *p <<"\n";
    *p =1000 ;
    cout<<"After changing ...\n";
    cout<<"a = " << a <<"\n";
    cout<<"*p = " << *p <<"\n";

    const int **q = const_cast<const int **>(&p);
    cout<<"After changing ...\n";
    cout<<"a = " << a <<"\n";
    cout<<"*p = " << *p <<"\n";
    cout<<"**q = " << **q <<"\n";
    
    // const int **r = const_cast<int **>(&a);
    const int *r = &a;

    // const int && r = const_cast<int &>(&a);
    cout<<"After changing ...\n";
    cout<<"a = " << a <<"\n";
    cout<<"*p = " << *p <<"\n";
    cout<<"**q = " << **q <<"\n";
    cout<<"*r = " << *r <<"\n";

    int *ptr = const_cast<int *>(r);
    *ptr =123234;
    cout<<"After changing ...\n";
    cout<<"a = " << a <<"\n";
    cout<<"*p = " << *p <<"\n";
    cout<<"**q = " << **q <<"\n";
    cout<<"*r = " << *r <<"\n";
    
}