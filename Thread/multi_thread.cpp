#include<iostream>
#include<thread>
#include<chrono>
using namespace std;

void * function_1 (void * a)
{
    for(;;)
    {
        cout<<".................. Thread 1 increment function ..................\n";
        int * ptr  = static_cast<int * > (a);
        *ptr = *ptr +1 ;
        cout<<"After the increment ..... : " << *ptr << endl ;
        std::this_thread::sleep_for(chrono::microseconds(182));
        
    }
    return nullptr ;
}

void * function_2 (void * a)
{
    for(;;)
    {
        cout<<".................. Thread 2 decrement function ..................\n";
        int * ptr  = static_cast<int * > (a);
        *ptr = *ptr -1 ;
        cout<<"After the increment ..... : " << *ptr << endl ;
        std::this_thread::sleep_for(chrono::microseconds(183));
        
    }
    return nullptr ;
}

int main()
{
    cout<<"This is the program to understand the single thread in c++ \n";
    pthread_t thread1, thread2;

    int number =0;
    void * ptr = static_cast<void *>(&number);
    if(pthread_create(&thread1 , NULL , function_1 , ptr )!=0)
    {
        cout<<"There is no problem on creating the thread 1 \n";
    }

    if(pthread_create(&thread2 , NULL , function_2, ptr )!=0)
    {
        cout<<"There is no problem in creating the thread 2 \n";
    }

    pthread_join(thread1,NULL);


}