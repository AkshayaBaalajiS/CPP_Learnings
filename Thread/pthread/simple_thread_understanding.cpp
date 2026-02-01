#include<iostream>
#include<pthread.h>
using namespace std ;

void* thread_function_1(void * arg)
{
    while(true)
    {
        cout<<"Thread_1 is running ......\n";
    }
    return nullptr;
}

void * thread_function_2(void * arg)
{
    while(true)
    {
        cout<<"Thread_2 is running ............\n";
    }
}
int main()
{
    pthread_t thread_1 , thread_2;
    if(pthread_create(&thread_1,NULL,thread_function_1,NULL)!=0)
    {
        cout<<"Pthread_1 creation is on problem \n";
        return 0;
    }

    if(pthread_create(&thread_2,NULL,thread_function_2,NULL)!=0)
    {
        cout<<"Pthread_2 creation is on problem \n";
        return 0;
    }

    cout<<"Thread created and the identifier for the thread is  :  " << thread_1<<"\n";
    pthread_join(thread_1,NULL);
    pthread_detach(thread_2); // we can ujse either pthread_join or pthread_detach ;

}