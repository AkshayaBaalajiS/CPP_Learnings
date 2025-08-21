#include<iostream>
using namespace std;

int main()
{
    cout<<"This is the program to undertsand the Octal conversion \n";
    
    string str;
    cout<<"Enter the octal number : ";
    cin>>str;

    int decimal = stoi(str,nullptr,8);
    cout<<"\nThe Decimal Number is : "<<decimal <<endl;

    cout<<"Octal number is  : "<<oct<<decimal<<endl;

    cout<<"Hex Decimal is : "<<hex<<decimal <<endl;

}