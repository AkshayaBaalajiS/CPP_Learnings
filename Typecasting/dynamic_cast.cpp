#include<iostream>
using namespace std;


class baseClass
{
    public :
        baseClass()
        {
            cout<<"baseClass constructor called \n";
        }
        virtual void class_function()
        {
            cout<<"This is the base class function ..\n";
        }
        ~baseClass()
        {
            cout<<"baseClass Destructor called \n";
        }
        
};
class derivedClass : public baseClass
{
    public :
        derivedClass()
        {
            cout<<"derivedClass constructor called \n";
        }

        void class_function() override
        {
            cout<<"This is the Derived class function ..\n";
        }
        ~derivedClass()
        {
            cout<<"derivedClass Destructor called \n";
        }
        
};



int main()
{
    cout<<"This is the program to understand the dynamic cast \n";

    int array[] = {1,2,3,4,5,6,7,8,9};
    int size=sizeof(array)/sizeof(array[0]);

    
    int * iPtr = array; 
    cout<<"The integer array is : ";
    for(int i=0;i<size;i++)
    {
        cout<<array[i] << "  " ;
    }
    cout<<endl;

    // comparision of the static cast and dynamic cast 
    float * fPtr =  new float [10] ;    
    /*
    float * fPtr = dynamic_cast<float * >(iPtr);    
    Since there’s no valid relationship between int* and float*, the compiler will immediately detect that this is an invalid cast and throw a compile-time error.
    */
   for(int i=0;i<size;i++)
   {
        fPtr[i]=static_cast<float>(array[i]); // here only the static cast will work because there is no inheritance or polymorphism of the float and int 
        // fPtr[i]=dynamic_cast<float>(array[i]); // the dynamic cast here will throw error because there is no inheritance or polymorphism of the float and int
   }

    cout<<"The float array is : ";
    for(int i=0;i<size;i++)
    {
        cout<<fPtr[i] << "  " ;
    }
    cout<<endl;


    // Dynamic cast on the class 
    derivedClass * dPtr;
    // baseClass * ptr = static_cast<baseClass *>(dPtr);
    baseClass * ptr = dynamic_cast<baseClass *>(dPtr); // both static and dynamic cast will work but the dynamic cast the check will on run time

}