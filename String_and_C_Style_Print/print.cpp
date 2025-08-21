#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int main()
{
    cout<<"This is the program to work on the print and the string in C++\n";
    string strVariable;
    strVariable="Akshaya Baalaji Senthilraj \n";
    char * name  = "Akshaya Baalaji Senthilraj\n";

    // printf("This is done by the print : %s" , strVariable ); // the string type is not compatible with the C style print
    printf("This is done by the print : %s" , strVariable.c_str() ); // the string type is not compatible with the C style print so we are using the c_str that will convert the string to const char * 

    cout<<endl;
    printf("This is done by the print : %s" , name);
}