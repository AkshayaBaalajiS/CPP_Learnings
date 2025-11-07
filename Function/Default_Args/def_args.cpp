#include<iostream>
using namespace std ;

// below is the function for the default arguments
void function_to_do_so(int a , int b=123)
{
    cout<< "A = " << a << " , B = " << b <<endl;
}

int main()
{
    int a =10;
    function_to_do_so(a);
}