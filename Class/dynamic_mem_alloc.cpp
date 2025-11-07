#include<iostream>
using namespace std;


class sampleClass
{
    int ivariable ;
    float fvariable;
    public :
        sampleClass()
        {
            cout<<"The default constructor for the sampleClass called..\n";   
        }

        void function_to_do_something(int arg1 , float arg2)
        {
            ivariable=arg1;
            fvariable=arg2;
            cout<<"Class variable ivariable : " << ivariable << "  fvariable : " << fvariable <<"\n";
        }

        ~sampleClass()
        {
            cout<<"Destructor of sampleClass called to free resource \n";
        }
};

int main()
{
    cout<<"This is the program to understand how the dynamic memory allocation done ..\n";

    sampleClass object ; // this is normally created obj stored on the stack  

    sampleClass * ptr = new sampleClass(); // here the ptr is dynamically allocated and the ptr will be stored on the heap 

    // sampleClass *ptr_1[5] = (sampleClass *)malloc(sizeof(object)); // this cant be done because the constructor cant be called 

    int size ;
    cout<<"Enter the size of the array ..\n";
    cin>>size ;
    
    sampleClass *ptr_1[size]; // here the constrctor and destructor should be called manually 
    
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++\n";
    for(int i=0;i<size;i++)
    {
        ptr_1[i]=new sampleClass(); // here for each obj we are dynamically allocating memory and the constructor called because of it 
    }

    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++\n";
    sampleClass object_array[size];  // the destructor will be called automatically 
    
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++\n";
    
    cout<<"-------------------------------------------------\n";
    cout<<"The accessing the class data member through pointer ..\n";
    int temp_var = 10;
    for(int i=0;i<size;i++,temp_var=temp_var+10)
    {
        ptr_1[i]->function_to_do_something(temp_var,temp_var);
    }    
    cout<<"-------------------------------------------------\n";
    

    for(int i=0;i<size;i++)
    {
        delete ptr_1[i]; // destructor called manually by deleting the mem allocated
    }

    // dynamic mem allocated by malloc 
    sampleClass * ptr_2 = (sampleClass *)malloc(sizeof(ptr));

    // if the space is not enough we are reallocating the memory
    ptr_2=(sampleClass *)realloc(ptr_2,sizeof(ptr));

    // dynamic mem allocated by calloc (5 * 8 ) 
    sampleClass * ptr_3 = (sampleClass *) calloc(5,sizeof(ptr));

}
