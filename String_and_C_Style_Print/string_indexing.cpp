#include<iostream>
using namespace std;

int main()
{
    cout<<"THis is a program to understand the string indexing \n";
    string str="Akshaya Baalaji S";
    cout<<"str[0]  =" << str[0] <<endl;

    string str1="ABS";
    cout<<"str1.size() = " << str1.size() << endl;

    string str2="";
    cout<<"str1.empty() = " << str1.empty() << endl;
    cout<<"str2.empty() = " << str2.empty() << endl;

    // cout<<"str1.reverse() = " << str1.reverse() << endl; // no reverse funciton available 
    cout<<"str2.empty() = " << str2.empty() << endl;

    // proof that empty string cant be inserted 
    // str2.insert(1,2,'a');
    // cout<<"str2.empty() = " << str2.empty() << endl;   // 0 
    // cout<<"str2= " << str2 << endl;   // 0 

    str1.insert(1,2,'a');
    cout<<"str1.empty() = " << str1.empty() << endl;   // 0 
    cout<<"str1= " << str1 << endl;   // 0 

    
}