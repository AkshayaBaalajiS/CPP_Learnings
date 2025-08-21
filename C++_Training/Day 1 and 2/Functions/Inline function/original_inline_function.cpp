#include<iostream>
using namespace std;

template <typename type1 >
inline type1 GETMAX(type1 x , type1 y)
{
    return (x+y*x-y);
}

template <typename type1 , typename type2 >
inline type1 GETMAX(type1 x,type2 y)
{
    return (x+y*x-y/x*y);
}
int main()
{
    int x=20 , y=30;
    int i=23.345 , j=56.235;

    // overloading 
    cout << "GETMAX(x,j)  :" << GETMAX<int,float>(j,x) << "\n";
    // overloading 
    cout << "GETMAX(x,j)  :" << GETMAX<float,float>(j,x) << "\n";
    
    // GETMAXid 
    cout << "GETMAX(x,j)  :" << GETMAX<int>(x,j) << "\n"; 
    //GETMAXii
}