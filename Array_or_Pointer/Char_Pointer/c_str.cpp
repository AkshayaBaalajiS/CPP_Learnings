#include<iostream>
using namespace std;

int main()
{
    cout<<"This is the program to understand the c_str() fucntion which is used for converting from char * to string \n";
    char arr[] = "Akshaya Baalaji S \n";

    // string str = arr.c_str();  // this is the proof that the arr is not having the c_Str() function 
    // cout<<"STRING IS  : " << arr.c_str();

    string str="Akshaya Baalaji Senthilraj";
    const char * constchar = str.c_str();

    cout<<"The c style representation os the string is  : " << *constchar <<endl; // dereferencing the (*) constchar pointer will give only one char because it holds only the starting address 
    cout<< " and the string is  : " << str <<endl;

}
/*
c_str() is a method associated with the std::string class 
that returns a C-style string representation of the std::string object
*/