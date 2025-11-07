#include <iostream>
using namespace std;

int main()
{
    int a =345;
    int b=234;
    
    cout<<" A = " << a<<endl;
    cout<<" B = " << b<<endl;
    
    auto lambda_fun = [=,&a](){
        a=3353 + b ;
        // b=234; // this cant be done 
    };
    
    lambda_fun();
    cout<<" A = " << a<<endl;
    cout<<" B = " << b<<endl;
    
    
}