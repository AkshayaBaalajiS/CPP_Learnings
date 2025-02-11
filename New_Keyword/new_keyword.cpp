#include<iostream>
using namespace std ;

class sampleClass
{
    public :
        sampleClass()
        {
            cout<<"The sampleClass constructor called ..\n";
        }

        // this is commented for seeing all type of new keyowrd overload (normal new keyword overload funciton )
        // void * operator new(size_t size)
        // {
        //     cout<<"This is the overloaded function for dynamic mem allocaiton ..\n";
        //     void * ptr = malloc(size);
        //     return ptr;
        // }

        // void operator delete(void * ptr)
        // {
        //     cout<<"This is the overloaded function for freeing mem allocation ..\n";
        //     free(ptr);
        // }


        ~sampleClass()
        {
            cout<<"The sampleClass destructor called ..\n";
        }
};

// template <typename t1>
// void * new(size_t size)
// {
//     cout<<"This is the overloaded function for dynamic mem allocaiton ..\n";
//     t1 obj = new (size) t1;
//     return obj;
// }




int main()
{
    cout<<"This is a program to understand the new keyword ..\n";

    // this is the normal new keyword overloading 
    sampleClass * ptr = new sampleClass(); // normal new keyword 

    // pointer to the buffer which contains the memory 
    int * buffer = (int *) malloc(sizeof(int));
    
    // this is with new with placement new 
    int * iptr = new(buffer) int(6);

    // buffer for the class 
    sampleClass * cptr = (sampleClass *) malloc(sizeof(ptr));
    // new placement on class 
    sampleClass * ptr_1 = new (cptr) sampleClass(); // placement new 

    // no throw example  
    sampleClass * ptr_2 = new(nothrow) sampleClass(); // new with no throw keyword 

    //  Dynamically allocate an array of 5 sampleClass objects
    sampleClass * ptr_3 = new sampleClass[5]; // new with subset 


    // new keyword overload 
    // this is the normal new keyword overloading 
    sampleClass * ptr_4  = new sampleClass();

    delete(ptr);
    delete(ptr_1);
    delete(ptr_2);
    delete[] (ptr_3);
    delete(ptr_4);
    
}