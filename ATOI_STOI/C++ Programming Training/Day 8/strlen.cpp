#include<iostream>
#include <cstring>
using namespace std;
int main ()
{
    char const  * ptr = "Hello Bye See you";
    char array[] = "Hello Bye See you";
    cout<<"The size of the pointer created : " << strlen(ptr) << "\n";
    cout<<"The size of the pointer created : " << strlen(array);
}