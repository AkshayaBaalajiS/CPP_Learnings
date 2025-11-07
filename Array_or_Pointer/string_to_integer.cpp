#include<iostream>
using namespace std;

int main()
{
    cout<<"This is a program to convert the string to integer\n";
    string str("123");
    cout<<"The string is  : " << str<<endl;

    int diff = 1 ;
    int size = str.size() ;
    cout<<"Size  = " << size <<endl;
    for(int i=0;i<str.size()-1;i++)
    {
        diff=diff*10;
    }
    cout<<"diff  =  " << diff <<endl;
    int number=0 ;
    for(int i=0;i<str.size();i++)
    {
        int tmep=str[i] - '0';
        number=number+(tmep*diff);
        diff=diff/10;
        cout<<"tmep = " << tmep <<endl;
    }
    cout<<"number = " << number<<endl;


}