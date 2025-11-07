#include<iostream>
#include <string>
// #include <cstir>
using namespace std;

int main()
{
    cout<<"Program to convert The binary to Octal \n";
    int number ;
    cout<<"Enter the binary number \n";
    cin>>number;

    string stri= to_string(number);
    cout<<"Stri  = " << stri <<endl;

    // int result_number=stoi(stri,nullptr,10);
    // cout<<"Decimal is   = " << result_number << endl;
    
    // int result_number_1=stoi(stri,nullptr,16);
    // cout<<"Hexa Decimal is   = " << result_number_1 << endl;

    // int result_number_2=stoi(stri,nullptr,8);
    // cout<<"Octal  is   = " << result_number_2 << endl;

    int result_number_3=stoi(stri,nullptr,2);  // binary to decimal 
    cout<<"Binary to Decimal is  is   = " << result_number_3 << endl; 

    cout<<"Octal is : " << oct << result_number_3 <<endl;
    cout<<"HExa Decimal is : " << hex << result_number_3 <<endl;   
     

}