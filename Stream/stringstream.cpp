#include <cstddef>
#include<sstream>
#include<iostream>

using namespace std;
int main()
{
    cout<<"Program to understand the string stream \n";
    stringstream ss ;
    string str ;
    cout<<"Enter a number in binary format \n";
    cin>>str;

    int binary_decimal = stoi(str,nullptr , 2);
    cout<<"Decimal  :  " << binary_decimal <<endl;
    cout<<endl;

    ss<<oct<<binary_decimal;

    int decimal_octal = stoi (ss.str());
    cout<<"Decimal connverted to octal is  :"<< decimal_octal <<endl;

    ss.str(""); // empty the string stream 
    ss.clear();  // remove the exception 

    ss<<hex<<binary_decimal;
    
    int decimal_hexadecimal =stoi(ss.str());
    cout<<"Decimal converted to Hexa Decimal " << decimal_hexadecimal<<"\n"<< endl;

    
}