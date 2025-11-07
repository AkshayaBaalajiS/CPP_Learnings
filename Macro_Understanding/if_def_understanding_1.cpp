#include <iostream>
using namespace std;

#define YES 0 

int main()
{
    cout<<"This is the program to undertsand the ifdef \n";
#ifdef YES
    cout<<"YES macro is defined somewhere \n";
#else 
    cout<<"YES macro is not defined \n";
#endif 
    cout<<"Out of ifdef and else \n";
}