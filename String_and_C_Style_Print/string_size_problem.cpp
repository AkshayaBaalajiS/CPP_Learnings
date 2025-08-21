#include<iostream>
using namespace std;

int main()
{
    cout<<"This is a program to understad the string or arr with \\n as input to string or array \n";

    char arr[]="\n";
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<"The size of the char array with \\n as input  : " << size <<"\n";


    char arrr[]="A";
    size=sizeof(arr)/sizeof(arr[0]);
    cout<<"The size of the char array with A as input  : " << size <<"\n";

    string str= "A";
    cout<<"The size of the string with A as input  : " << str.size() <<"\n";

    string strr= "\n";
    cout<<"The size of the string with \\n as input  : " << strr.size() <<"\n";

    

}