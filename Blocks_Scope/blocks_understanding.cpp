#include<iostream>
using namespace std;

#define TEST(x,y,z) x=100;y=100;z=100

int main ()
{
    cout<<"This code is to understand the importance of the blocks \n";
    int a = 5 ;
    // int b,c =12 ; //  here the b is local variable and the value is not assigned so garbage value 
    int b=11 ,c =12 ; //  here the b is local variable and the value is not assigned so garbage value 
    cout << "A = " << a  <<" B  = " << b << " C  = " << c << "\n";
    cout << "----------------------------\n";
    
    // without blocks works wrong 
    // if (a<5)
    //     TEST(a,b,c);

    // With blocks works crt 
    if (a<5)
    {
        TEST(a,b,c);
    
    }
        cout<< "+++++++++++++++++++++++++++++\n";
    cout << "A = " << a <<" B  = " << b << " C  = " << c << "\n";
    cout << "----------------------------\n";
      
}