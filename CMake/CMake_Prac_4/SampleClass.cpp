#include "SampleClass.h"

#ifdef SAMPLE_CLASS
Sample::Sample() : a(0) , b(0) , c(0) , d(0)
{
    cout<<"@ Sample Class Constructor \n";
}

Sample::Sample(int a, float b, char c, double d, int * val , int * val_1)
{
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
    
    this->shallow_data  = val;
    this->deep_data  = val_1;
    

}

Sample::~Sample()
{
    cout<<"@ Sample Class Destructor \n";
}

// deep copy 
Sample::Sample(Sample & ref)
{
    this->a = ref.a;
    this->b = ref.b;
    this->c = ref.c;
    this->d = ref.d;

    // this is shallow copy 
    this->shallow_data = ref.shallow_data;

    // this is deep copy
    this->deep_data = new int(*ref.deep_data);
}

void Sample::setValues(int a, float b, char c, double d , int val , int val_1)
{
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d; 

    *(this->shallow_data) = val;
    *(this->deep_data) = val_1;
}

void Sample::printValues()
{
    cout<<"Int  = " << a <<endl;
    cout<<"Float  = " << b <<endl;
    cout<<"Char  = " << c <<endl;
    cout<<"Double  = " << d <<endl;

    cout<<"Shallow_Data =  " << *shallow_data <<endl;
    cout<<"Deep Data =  " << *deep_data <<endl;
    
}
#endif