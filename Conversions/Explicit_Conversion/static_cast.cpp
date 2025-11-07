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
    cout<<"This is program to understand static_cast in C++\n";
    // we cant directly assign the values to pointer 
    // int * ptr = 23;
    // cout<<"The *ptr : " << *ptr <<endl;

    // we cant assign a pointer with the vairble / other than address we cant assign anything
    // int samplevariable=12;
    // int * ptr_1 = samplevariable;

    int array[]={1,2,3,4,5};
    int * ptr_2 = array;

    int sizeOfArray=sizeof(array)/sizeof(array[0]);
    for(int i=0;i<sizeOfArray;i++)
    {
        cout<<ptr_2[i] << " ";
    }
    cout<<endl;

    // Static cast on Primitive types  : 
    // float * flaot_ptr = static_cast<float *>(ptr_2); //. even the types are known before the compile time this is not safe conversion so compiler throws error 

    float * flaotPointer = new float[10] ;
    // casting assigning
    for(int i=0;i<sizeOfArray;i++)
    {
        flaotPointer[i]=static_cast<float>(array[i]);
    }

    // printing 
    for(int i=0;i<sizeOfArray;i++)
    {
        cout<<flaotPointer[i] << " ";
    }
    cout<<endl;

    // static cast on the class 
    derivedClass d_Object ;

    derivedClass * dPtr;
    dPtr = &d_Object;

    baseClass * bPtr = static_cast<baseClass *>(dPtr);  
    // baseClass * bPtr = dynamic_cast<baseClass *>(dPtr); // here this both works same bu the checking will be at the run time   
    bPtr->class_function(); // this is the use of the staic cast 

}