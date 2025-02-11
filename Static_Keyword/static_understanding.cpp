#include<iostream>
using namespace std;



void static_increment_function()
{
    static int sgiVar ;
    ++sgiVar;
    cout<<"The value of sgiVar : " << sgiVar <<"\n";
}


void non_static_increment_function()
{
    int nsgiVar =0;
    ++nsgiVar;
    cout<<"The value of nsgiVar : " << nsgiVar <<"\n";
}


int main()
{
    cout<<"This is a program to understand the static keyword on local and global scope \n";
    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n";
    static_increment_function();
    static_increment_function();
    static_increment_function();
    static_increment_function();
    static_increment_function();
    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n";
    non_static_increment_function();
    non_static_increment_function();
    non_static_increment_function();
    non_static_increment_function();
    non_static_increment_function();
    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n";

    
}