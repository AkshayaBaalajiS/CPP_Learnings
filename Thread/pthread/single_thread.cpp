#include<iostream>
#include<thread>
#include<chrono>
using namespace std;

void * function_1 (void * a)
{
    for(;;)
    {
        cout<<".................. Thread 1 function ..................\n";
        int * ptr  = static_cast<int * > (a);
        *ptr = *ptr +1 ;
        cout<<"After the increment ..... : " << *ptr << endl ;
        std::this_thread::sleep_for(chrono::seconds(1));
        
    }
    return nullptr ;
}

int main()
{
    cout<<"This is the program to understand the single thread in c++ \n";
    pthread_t thread1 ;

    int number =0;
    void * ptr = static_cast<void *>(&number);
    if(pthread_create(&thread1 , NULL , function_1 , ptr )!=0)
    {
        cout<<"There is no problem on creating the thread 1 \n";
    }

    pthread_join(thread1,NULL);


}