#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

int volatile flag = 0 ;
int main()
{
    cout<<"This is a program to understand the volatile and how it works \n";

    while(flag>=0)
    {
        cout<<"Here the flag value is checked in the memory rather than from cache everytime this is the use of volatile \n";
        cout<<"This is useful when it is accessed by some other thread and the thread will get the most recent value from memory through volatile keyword \n";
        cout<<"\n\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

}