#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    cout<<"This is the program to understand sizeof and strlen \n";

    char name_array[]="Akshaya Baalaji Senthilraj";
    char * name_ptr= "Akshaya Baalaji Senthilraj";
    string name_string = "Akshaya Baalaji Senthilraj";
    string name_string_1; // the size of the string is 4 bytes 
    
    cout<<"The sizeof the name array : " << sizeof(name_array)/sizeof(name_array[0])<<endl;
    cout<<"The sizeof name pointer : " << sizeof(name_ptr)<<endl;
    // the below 2 sizeof on a string is a proof that the sizeof gives the object size 
    cout<<"The sizeof name string : " << sizeof(name_string)<<endl; 
    cout<<"The sizeof name string_1 : " << sizeof(name_string_1)<<endl;
    cout<<"The sizeof int is  : " << sizeof(int)<<endl;
    cout<<"The sizeof string is  : " << sizeof(string)<<endl; // returns the size of the object
    
    
    cout<<"The size name string : " << name_string.size()<<endl;
    cout<<"The capacity name string : " << name_string.capacity()<<endl;
    
    
    // strlen is only for the const char * type 
    // cout<<"The strlen the name array : " << strlen(name_array);
    cout<<"The strlen name pointer : " << strlen(name_ptr)<<endl;
    // cout<<"The strlen name string : " << strlen(name_string);


       
}