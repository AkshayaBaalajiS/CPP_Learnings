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
                cout<<"@ Destructor"<<this <<" \n";
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
        /*
        ptr = new(nothrow) A();  //  nothrow is for the overloading at runtime 
        //A() willl only call the constructor not the destructor 
        //nothrought - is overloaded new operator like malloc in the (C)
        */

        try {
            //this is new with subscript 
            ptr = new A[5];  // this new A[5] will call the constructor 5 times 
        }
        catch (...){
            cout<<"Bad new keyword usage \n";
        }
        
        cout <<"ptr after new keyword holds " << ptr <<"\n";
        
        if(NULL == ptr )
        {
            cout<<"Pointer is NULL now \n";
        }

        //the below stmt only call destructor for one object (the first object)
        // delete(ptr); // this only calls the destructor or else the destructor wont get called
        
        //how to access the objects created from the new with subscript 
        ptr->display();

        ptr[1].display();
        
        ptr[2].display();

        ptr[3].display();

        ptr[4].display();

        //the below delete with subscript call all the number of the object created by the new with subscript 
        delete [] ptr ;

    }
    /*


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


