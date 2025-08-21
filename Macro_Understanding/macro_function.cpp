#include<iostream>
#include<string.h>
using namespace std;
// below if for testing the macro expansion 
#define FUNC(x) x*x 

#define VALUE 10

int main()
{
    // this is a comment that will be removed at the preprocessor time 
    cout<<"This is the code for testing the preprocessor way of the code \n";
    int a=10 ;
    int b=20 ;
    int c = FUNC(a+b) ; // this will be executed like (a+b) * (a+b)  10 + 20 * 10 + 20 = 230 
    cout<<"After the macro expansion :   " << c << endl ; 
    int d = VALUE;
    cout<< "After the macro expansion :   " << d << endl ;
}