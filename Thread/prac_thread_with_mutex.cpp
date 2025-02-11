#include<iostream>
#include<pthread.h>

#include <chrono>
#include<thread>

#include<mutex>

using namespace std ;

struct Struct_A
{
    int a;
    float b ;
    char * str;
    double d ;
    int size_of_var;
};

mutex mutex_variable ;
void * increment_function(void * ptr)
{
    Struct_A * str_ptr = static_cast<Struct_A * >(ptr);
    cout<<"The thread will continuously print the structure data member ...\n";
    while(1)
    {
        cout<<"\n";
        mutex_variable.lock();
        str_ptr->a++;
        str_ptr->b++;
        str_ptr->d++;

        cout<<"Int variable  : " << str_ptr->a << "\n";
        cout<<"Float variable  : " << str_ptr->b << "\n";
        cout<<"Char *  variable  : " ;
        for (int i=0;i<str_ptr->size_of_var ; i++ )
        {
            cout<< str_ptr->str[i] << " " ;
        }
        cout<<"\n";
        cout<<"Double variable  : " << str_ptr->d << "\n";
        mutex_variable.unlock();

        this_thread::sleep_for(chrono::milliseconds(180));
    }
}


void * decrement_function(void * ptr)
{
    cout<<"\n";
    Struct_A * str_ptr = static_cast<Struct_A * >(ptr);
    cout<<"The thread will continuously print the structure data member ...\n";
    while(1)
    {
        cout<<"\n";

        mutex_variable.lock();
        str_ptr->a--;
        str_ptr->b--;
        str_ptr->d--;

        cout<<"Int variable  : " << str_ptr->a << "\n";
        cout<<"Float variable  : " << str_ptr->b << "\n";
        cout<<"Char *  variable  : " ;
        for (int i=0;i<str_ptr->size_of_var ; i++ )
        {
            cout<< str_ptr->str[i] << " " ;
        }
        cout<<"\n";
        cout<<"Double variable  : " << str_ptr->d << "\n";
        mutex_variable.unlock();
        this_thread::sleep_for(chrono::milliseconds(185));
    }
}
int main()
{
    Struct_A * ptr =new Struct_A();
    ptr->a=1;
    ptr->b=1.0;

    char name[]="Akshaya Baalaji Senthilraj";
    ptr->str=name;
    ptr->size_of_var = sizeof(name)/sizeof(name[0]);
    
    ptr->d=1.000;

    pthread_t thread_1 , thread_2 ;
    if(pthread_create(&thread_1 , NULL , increment_function , ptr)!=0)
    {
        cout<<"Thread creation is on problem ..\n";
        return 0 ; 
    }
    cout<<"There is no problem in thread_1 creation \n";

    if(pthread_create(&thread_2 , NULL , decrement_function , ptr)!=0)
    {
        cout<<"Thread creation is on problem ..\n";
        return 0 ; 
    }
    cout<<"There is no problem in thread_1 creation \n";

    
    pthread_join(thread_1,NULL);
    pthread_detach(thread_2);

}