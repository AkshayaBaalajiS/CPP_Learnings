#include<iostream>
#include<string.h>
using namespace std;

bool function_to_check_char_pointer_is_palindrome(char * name , int size)
{
    bool flag = false ;
    char buffer[size] ;
    
    for(int i=size-2,j=0;i>=0;i--,j++)
    {
        // cout<<"name[<<" << i<< " <<]"<<name[i]<<"    " ;
        buffer[j]=name[i];
    }
    
    // cout<<endl<<endl;

    for(int i=0;i<size-1;i++)
    {
        cout<<buffer[i] <<  "   " ; 
    }
   
    if(strcmp(name , buffer)==0)
    {
        return true ;
    }
    else{
        return false;
    }

}


bool function_to_check_string_is_palindrome(string str)
{
    string temp = str;
    
    string result = "";

    for(int i=0,j=str.size()-1;i<str.size();i++,j--)
    {
        // result[i]=str[j];  // this should not be done like char 
        result+=str[j]; // this should be done like this 
    }
    cout<<"the reversed string is  " <<result << endl;
    // return true;
    if(result.compare(temp)==0)
    {
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    cout<<"This is a program to understand the char and string comparision and function can be used \n";
    // for string the last char will be \0
    char name[] = "Akshaya baalaji Senthilraj";
    // char name[] = "Akshaya"; 
    char * name_ptr=name;

    cout<<"sizeof(name)  " << sizeof(name) << endl;
    cout<<"sizeof(name[0])   "<<sizeof(name[0]) << endl;
    
    int size = sizeof(name)/ sizeof(name[0]);

    // for(int i=0;i<size-1;i++)
    // {
    //     cout<<"name[<<" << i<< " <<]"<<name[i]<<"    " ;
    // }
    // cout<<endl<<endl;

    bool result = function_to_check_char_pointer_is_palindrome(name , size);
    if(result)
    {
        cout<<"Palindrome \n";

    }
    else{
        cout<<"Not a palindrome\n";
    }


    // now string palindrome 

    string str ="Akshaya Baalaji Senthilraj";
    cout<<"str.size()   " << str.size() <<endl;
    // cout<< "string result = " << function_to_check_string_is_palindrome(str);  // thsi will return but no stmt to catch that return that too no error 
    bool result_1 = function_to_check_string_is_palindrome(str);  // thsi will return but no stmt to catch that return that too no error 
    
    if(result_1)
    {
        cout<<"Palindrome";

    }
    else{
        cout<<"Not a palindrome\n";
    }
}