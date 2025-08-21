#include<iostream>
using namespace std;

void function_call_by_value(int a , int b )
{
    cout<<"This is a call by value function " << endl << "A = " << a << "  B = " << b <<endl;
}


void function_call_by_reference(int * a , int * b)
{
    cout<<"This is a call by value function " << endl << "A = " << *a << "  B = " << *b <<endl;
}


int main()
{

    int a = 10;
    int b = 20;

    function_call_by_value(a,b);
    
    function_call_by_reference(&a,&b);
    


}