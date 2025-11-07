#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    cout<<"This si the program to find the length of the string \n";
    string string_1 = "Akshaya Baalaji Senthilraj";

    cout<<"the string len usign the size  : " << string_1.size()<<endl;
    cout<<"the string len usign the strlen  : " << strlen(string_1.c_str())<<endl;
    cout<<"the string len usign the length  : " << string_1.length()<<endl;
    
}