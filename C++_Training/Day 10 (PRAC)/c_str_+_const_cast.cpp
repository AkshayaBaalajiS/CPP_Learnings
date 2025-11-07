#include <iostream>
#include <cstring> // For strcpy
#include <string>  // For std::string
using namespace std;

int main() {
    // Define a C++ string
    string cppString = "Hello, world!";

    // Allocate memory for the C-style string
    char* cString = new char[cppString.length() + 1]; // +1 for null terminator

    // Copy the contents of the C++ string to the C-style string
    strcpy(cString, cppString.c_str());

    // Print the C-style string
    cout << "C-style string: " << cString << endl;

    cout<<"-------------------\n";
    const char * ptr = cppString.c_str();
    cout<< "The value is  : " << ptr  << "\n";
    cout<<"-------------------\n";

    //we are trying the convertion of the const char * to char * 

    char * ptr_1 = const_cast <char *>(ptr) ;


    // Don't forget to free the allocated memory
    delete[] cString;

    return 0;
}