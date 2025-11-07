#include <iostream>
#include <vector>
// #include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main()
{
    cout<<"This is the program to understand the conver the intger to binary\n";
    cout<<"Enter a number to convert it to binary  : ";
    int number ;
    cin>>number ;
    
    vector<int> binary_of_number ;
    int rem =0 ;
    while(number>0)
    {
        cout<<number << " ------------------------"<<endl;
        rem = number % 2 ;
        binary_of_number.push_back(rem);
        number=number/2 ;
    }
    reverse(binary_of_number.begin(),binary_of_number.end());
    for(int i :  binary_of_number)
    {
        cout<<i << "  " ;
    }
    cout<<endl;
}