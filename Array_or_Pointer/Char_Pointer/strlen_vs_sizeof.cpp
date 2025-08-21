#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main()
{
    string str="Akshaya Baalaji S";
    cout<<"the size str is  : " << str.size() <<endl;

    const char *  arr = str.c_str();
    cout<<"the strlen of te str is : " << strlen(arr) << endl;

}