#include<iostream>
using namespace std;

struct A_Structure 
{
    int integer ;
    float float_variable;
    char * name ;
};

// function declaration 
void * function_to_do_something(void * args );

int main()
{
    cout<<"This is a function understanding program ...\n";

    A_Structure * ptr = new A_Structure;

    void * v_ptr = static_cast<void *> (ptr);
    char name[20];
    
    ptr->float_variable=12.232;
    ptr->integer=1234;

    cout<<"Enter your name : ";
    cin.getline(name,20);

    ptr->name=name;
    
    //function call 
    function_to_do_something(v_ptr); // arguments v_ptr
}

// funciton definition 
void * function_to_do_something(void * args )  // parameter void * 
{//prologue 
    
    // body
    cout<<"This is the function to do something ....\n";
    A_Structure * ptrr = static_cast<A_Structure *>(args);

    cout<<"----------------- STRUCTURE PRINTING -------------------\n";
    cout<<"INTERGER VARIABLE = "<< ptrr->integer << "\n";
    cout<<"FLOAT VARIABLE = "<< ptrr->float_variable << "\n";
    cout<<"NAME : ";
    for(int i=0;i<20 ; i ++ )
    {
        cout<<ptrr->name[i]<<" ";
    }
    cout<<"\n";

    cout<<"--------------------------------------------------------\n";
    

    return nullptr;
}// epilogue
