#include<iostream>
using namespace std ;

void  add(int a , int b=-1) 
{
    cout <<"A = " << a  << "  B = " << b <<"\nA+B = " << a+b <<"\n";
}
void add(double a ,double b=-1)
{
    cout <<"A = " << a  << "  B = " << b <<"\nA+B = " << a+b <<"\n";
}
// It wont work normally here 
// void add(double a ,double b=-1)
// {
//     cout <<"A = " << a  << "  B = " << b <<"\nA+B = " << a+b <<"\n";
// }
// void add(int a )
// {
//     cout <<"A = " << a <<"\n";
// }


int main()
{
    //funciton overloading 
    add(11.0,11.0);
    add(11,11);

    // function overriding 
    add(11.12,23.3);
}