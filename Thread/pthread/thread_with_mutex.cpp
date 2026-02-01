#include<iostream>
#include<pthread.h>

#include<chrono>
#include<thread>


#include <mutex>
using namespace std;


mutex mutex_var;
struct A
{
    int a ;
    char *arr;
    float c;
    int size_of_name;
};

void *print_data_member_1(void * arg)
{
    // while(true)
    // {
    //     cout<<"------------------------ Thread 1 function ------------------------\n";
    //     this_thread::sleep_for(chrono::milliseconds(100));    
    // }

    while(true)
    {
        mutex_var.lock();
        cout<<"------------------------ Thread 1 function ------------------------\n";
        A * ptr = static_cast<A *> (arg);
        cout<<"Int DataMember :  " << ptr->a <<"\n";
        cout<<"Float DataMember :  " << ptr->c << "\n";
        cout<<"Size of array is  : " << ptr->size_of_name <<"\n"; 
        cout<<"String is  : " ;
        for (int i=0;i<ptr->size_of_name;i++)
        {
            cout<<ptr->arr[i] << " " ;
        }
        cout<<"\n";
        ptr->a=ptr->a+1;
        ptr->c=ptr->c+1;
        mutex_var.unlock();
        std::this_thread::sleep_for(chrono::milliseconds(200));
    }
    return nullptr;
}
void *print_data_member_2(void * arg)
{
    // while(true)
    // {
    //     cout<<"------------------------ Thread 2 function ------------------------\n";
    //     this_thread::sleep_for(chrono::milliseconds(90));    
    // }
    
    while(true)
    {
        cout<<"------------------------ Thread 2 function ------------------------\n";
        A * ptr = static_cast<A *> (arg);
        cout<<"Int DataMember :  " << ptr->a <<"\n";
        cout<<"Float DataMember :  " << ptr->c << "\n";
        cout<<"Size of array is  : " << ptr->size_of_name <<"\n"; 
        cout<<"String is  : " ;
        for (int i=0;i<ptr->size_of_name;i++)
        {
            cout<<ptr->arr[i] << " " ;
        }
        cout<<"\n";

        ptr->a=ptr->a+1;
        ptr->c=ptr->c+1;
        std::this_thread::sleep_for(chrono::milliseconds(180));
    }
    return nullptr;
}


int main()
{
    cout<<"Structure data member acceess program ......\n";
    pthread_t thread_1 , thread_2 ;
    
    char name[]="Akshaya Baalaji Senthilraj";

    int size=sizeof(name)/sizeof(name[0]);

    A * ptr =new A();
    ptr->a=10;
    ptr->arr=name;
    ptr->c=20.34353;
    ptr->size_of_name=size;

    void * v_ptr = static_cast<A*>(ptr);

    if(pthread_create(&thread_1 , NULL ,print_data_member_1 , v_ptr )!=0)
    {
        cout<<"Pthread_1 Creation problem \n";
        return 0;
    }
    cout <<"Pthread_1 created with no problem ...\n";
    
    
    if(pthread_create(&thread_2,NULL , print_data_member_2, v_ptr)!=0)
    {
        cout<<"Pthread_2 Creation problem \n";
        return 0;
    }
    cout <<"Pthread_2 created with no problem ...\n";
    
    pthread_join(thread_1,NULL);
    pthread_join(thread_2,NULL);
    

}