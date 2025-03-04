#include<iostream>
using namespace std ;

namespace group1
{
    class A 
    {
        int variable ;
        public :
            A(int args = -1 )
            {
                variable = args ; 
                cout<<"@ Constructor "<< this <<"\n";
            }
            ~A()
            {
                cout<<"@ Destructor  "<<this <<" \n";
            }
            void display()
            {
                cout<<"From " << this <<" The value of variable in class is :" << variable << " \n"; 
            }
    };
    void main()
    {
        // A *ptr  ; If = NULL not defined it hold some random address 
        A * ptr = NULL ;
        cout <<"ptr holds " << ptr <<"\n";
        
        ptr = new(nothrow) A(10);  //  nothrow is for the overloading at runtime 
        //A() willl only call the constructor not the destructor 
        //nothrought - is overloaded new operator like malloc in the (C)
        
        cout <<"ptr holds " << ptr <<"\n";
        
        ptr->display();
        
        //the below delete with subscript call all the number of the object created by the new with subscript 
        delete ptr ;

        ptr=NULL;
        cout <<"ptr holds " << ptr <<"\n";


    }
    /*
    This is how the overloading happen in Background 
    void* operator new [] (size_t size )
    {
        void * temp = malloc(size);
        if(tmp)
            return tmp ;
        throw bad_alloc();
    }
    
    */
}

int main()
{
    group1::main();
}


