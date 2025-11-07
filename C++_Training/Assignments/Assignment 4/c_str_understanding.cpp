#include<iostream>
#include<cstring>
#include<string>
using namespace std ;

int main()
{
    cout <<"Here we are converting a String to char * \n";
    string str = "Akshaya Baalaji SenthilRaj";
    cout<<"str -----------> " << str  << "\n";
    char  *ptr = new char [(strlen(str.c_str()) + 1)] ;  // new char [(strlen(str.c_str()) + 1)] ; for allocating the memory 
    strcpy(ptr ,str.c_str());   // c_str() is a function to convert the string to char * 
    // strcpy(ptr ,str);   // error : no suitable conversion function from "std::__cxx11::string" 
                        // (aka "std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>") to "const char *"
    cout<<"ptr -----------> " << ptr << "\n";

}
