#include<iostream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
    cout<<"This is the program to understand how the strcpy works \n";
    char arr[40];
    string str = "Akshaya Baalaji Senthilraj";

    // way 1 for the copying the data from the string to char arr
    cout<< "way 1 for the copying the data from the string to char arr\n";
    strcpy(arr,str.c_str());
    cout<<"\n";
    for(int i=0;i<str.size();i++)
    {
        cout<<arr[i] << "   " ;
    }
    cout<<"\n\n";

    // way 2 for copyig the string to const char * 
    cout<<"way 2 for copyig the string to const char * \n";
    const char * c_string = str.c_str();

    for(int i=0;i<str.size();i++)
    {
        cout<<c_string[i] << "   " ;
    }
    cout<<"\n\n";

    cout<<"way 3 for copying the data from the string to char * \n";
    const  char * c_strr = str.c_str();
    char * carr = const_cast<char *>(c_strr);

    for(int i=0;i<str.size();i++)
    {
        cout<<carr[i] << "   " ;
    }
    cout<<"\n\n";
    
}