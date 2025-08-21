// The below code is a perfect example to show the macro get executed before compile time 

#include<iostream>
using namespace std;
#define VALUE(x)  VALUE = x

int main()
{
    cout<<"This program is for understanding what not to do with namespace \n";
    int number ;
    cout<<"Enter a number : " ;
    cin>>number;
#if VALUE>10 
    cout<<"The number is greater that 10 \n";
#endif

}

