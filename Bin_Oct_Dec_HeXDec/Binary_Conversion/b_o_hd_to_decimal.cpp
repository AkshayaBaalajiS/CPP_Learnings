#include<iostream>

using namespace std;
int main()
{
    cout<<"Program to understand the string stream \n";
    string str ;
    cout<<"Enter a number in binary format \n";
    cin>>str;

    int binary_decimal = stoi(str,nullptr , 2);
    cout<<"Decimal  :  " << binary_decimal <<endl;
    cout<<endl;
    cout<<"Enter a number in Hexa decimal format \n";
    cin>>str;

    int hexadecimal_decimal = stoi(str,nullptr , 16);
    cout<<"Hexa Decimal to Decimal is : " << hexadecimal_decimal<<endl;
    cout<<endl;


    cout<<"Enter a number in Octal format \n";
    cin>>str;

    int octal_decimal = stoi(str,nullptr , 8);
    cout<<"Hexa Decimal to Decimal is : " << octal_decimal<<endl;
    cout<<endl;

}