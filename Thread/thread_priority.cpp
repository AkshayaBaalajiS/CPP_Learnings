#include<iostream>
#include<pthread.h>

#include <chrono>
#include<thread>

#include<mutex>

// #include <sched.h>

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
        {
                cout<<"\n";
            cout<<"Thread 1 is running the below  ..... \n";
            lock_guard lock(mutex_variable);
            // mutex_variable.lock();
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
            // mutex_variable.unlock();

            this_thread::sleep_for(chrono::milliseconds(180));
        }
    }
}


void * decrement_function(void * ptr)
{
    cout<<"\n";
    Struct_A * str_ptr = static_cast<Struct_A * >(ptr);
    cout<<"The thread will continuously print the structure data member ...\n";
    // lock_guard lock(mutex_variable);
    while(1)
    {
        {
            cout<<"\n";
            cout<<"Thread 2 is running the below  ..... \n";
            lock_guard lock(mutex_variable);

            // mutex_variable.lock();
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
            // mutex_variable.unlock();
            this_thread::sleep_for(chrono::milliseconds(185));
        }
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

    struct sched_param  obj_1;
    obj_1.sched_priority=55;

    struct sched_param  obj_2;
    obj_2.sched_priority=20;



    pthread_t thread_1 , thread_2,thread_3 ;
    if(pthread_create(&thread_1 , NULL , increment_function , ptr)!=0)
    {
        cout<<"Thread creation is on problem ..\n";
        return 0 ; 
    }
    cout<<"There is no problem in thread_1 creation \n";
   
    if(pthread_setschedparam(thread_1,SCHED_FIFO,&obj_1)!=0)
    {
        cout<<"Setting the thread priority has problem ..\n";
    }
    cout<<"Thread priority for thread_1 is done \n";



    if(pthread_create(&thread_2 , NULL , decrement_function , ptr)!=0)
    {
        cout<<"Thread creation is on problem ..\n";
        return 0 ; 
    }
    cout<<"There is no problem in thread_1 creation \n";

    if(pthread_setschedparam(thread_2,SCHED_FIFO,&obj_2)!=0)
    {
        cout<<"Setting the thread priority has problem ..\n";
    }
    cout<<"Thread priority for thread_2 is done \n";
    
    
    if(pthread_create(&thread_3 , NULL , decrement_function , ptr)!=0)
    {
        cout<<"Thread creation is on problem ..\n";
        return 0 ; 
    }
    cout<<"There is no problem in thread_3 creation \n";

    if(pthread_setschedparam(thread_3,SCHED_FIFO,&obj_2)!=0)
    {
        cout<<"Setting the thread priority has problem ..\n";
    }
    cout<<"Thread priority for thread_3 is done \n";
    
    pthread_join(thread_1,NULL);
    // pthread_join(thread_2,NULL);
    // pthread_join(thread_3,NULL);
    
    pthread_detach(thread_2);

}
//in the below program the thread 2 will only be running that is because of the priority 
// #include<iostream>
// #include<pthread.h>

// #include <chrono>
// #include<thread>

// #include<mutex>

// // #include <sched.h>

// using namespace std ;

// struct Struct_A
// {
//     int a;
//     float b ;
//     char * str;
//     double d ;
//     int size_of_var;
// };

// mutex mutex_variable ;
// void * increment_function(void * ptr)
// {
//     Struct_A * str_ptr = static_cast<Struct_A * >(ptr);
//     cout<<"The thread will continuously print the structure data member ...\n";
//     while(1)
//     {
//         cout<<"\n";
//         cout<<"Thread 1 is running the below  ..... \n";
//         mutex_variable.lock();
//         str_ptr->a++;
//         str_ptr->b++;
//         str_ptr->d++;

//         cout<<"Int variable  : " << str_ptr->a << "\n";
//         cout<<"Float variable  : " << str_ptr->b << "\n";
//         cout<<"Char *  variable  : " ;
//         for (int i=0;i<str_ptr->size_of_var ; i++ )
//         {
//             cout<< str_ptr->str[i] << " " ;
//         }
//         cout<<"\n";
//         cout<<"Double variable  : " << str_ptr->d << "\n";
//         mutex_variable.unlock();

//         this_thread::sleep_for(chrono::milliseconds(180));
//     }
// }


// void * decrement_function(void * ptr)
// {
//     cout<<"\n";
//     Struct_A * str_ptr = static_cast<Struct_A * >(ptr);
//     cout<<"The thread will continuously print the structure data member ...\n";
//     // lock_guard lock(mutex_variable);
//     while(1)
//     {
//         {
//             cout<<"\n";
//             cout<<"Thread 2 is running the below  ..... \n";
//             lock_guard lock(mutex_variable);

//             // mutex_variable.lock();
//             str_ptr->a--;
//             str_ptr->b--;
//             str_ptr->d--;

//             cout<<"Int variable  : " << str_ptr->a << "\n";
//             cout<<"Float variable  : " << str_ptr->b << "\n";
//             cout<<"Char *  variable  : " ;
//             for (int i=0;i<str_ptr->size_of_var ; i++ )
//             {
//                 cout<< str_ptr->str[i] << " " ;
//             }
//             cout<<"\n";
//             cout<<"Double variable  : " << str_ptr->d << "\n";
//             // mutex_variable.unlock();
//             this_thread::sleep_for(chrono::milliseconds(185));
//         }
//     }
// }
// int main()
// {
//     Struct_A * ptr =new Struct_A();
//     ptr->a=1;
//     ptr->b=1.0;

//     char name[]="Akshaya Baalaji Senthilraj";
//     ptr->str=name;
//     ptr->size_of_var = sizeof(name)/sizeof(name[0]);
    
//     ptr->d=1.000;

//     struct sched_param  obj_1;
//     obj_1.sched_priority=20;

//     struct sched_param  obj_2;
//     obj_2.sched_priority=55;



//     pthread_t thread_1 , thread_2 ;
//     if(pthread_create(&thread_1 , NULL , increment_function , ptr)!=0)
//     {
//         cout<<"Thread creation is on problem ..\n";
//         return 0 ; 
//     }
//     cout<<"There is no problem in thread_1 creation \n";
   
//     if(pthread_setschedparam(thread_1,SCHED_FIFO,&obj_1)!=0)
//     {
//         cout<<"Setting the thread priority has problem ..\n";
//     }
//     cout<<"Thread priority for thread_1 is done \n";



//     if(pthread_create(&thread_2 , NULL , decrement_function , ptr)!=0)
//     {
//         cout<<"Thread creation is on problem ..\n";
//         return 0 ; 
//     }
//     cout<<"There is no problem in thread_1 creation \n";

//     if(pthread_setschedparam(thread_2,SCHED_FIFO,&obj_2)!=0)
//     {
//         cout<<"Setting the thread priority has problem ..\n";
//     }
//     cout<<"Thread priority for thread_2 is done \n";
    
    
//     pthread_join(thread_1,NULL);
//     pthread_detach(thread_2);

// }
