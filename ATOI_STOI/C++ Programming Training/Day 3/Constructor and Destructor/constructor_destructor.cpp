#include<iostream>
using namespace std ;

class new_class
{
    public :
        //need of constructor if for the main function to allocate the memory to the another function 
        //thiscall new_class(new_class * const this )
        new_class()
        {
            cout<<"Automatically get called at time of creating a object " <<"\n ";
            cout << "A = " << a <<  "\n";
            cout << "B = " << b <<  "\n";
            cout << "C = " << c <<  "\n";
        }
        //When we are allocating the resource to object we need destructor to remove it 
        //thiscall new_class::~new_class (new_class * const this )
        ~new_class()
        {
            cout<<"Resource get deallocated \n";
        }
    public :
        int a=10 ;    
    private :  
        int b=20 ;    //new_class::b
    protected : 
        int c;    
    public :    
        void print_address()
        {
            cout<<"This =   "<< this <<"\n"; // in this (this) keyword the object address will be passed 
        }
};

int main()
{
    
    //object creation 
    new_class object_1 ;// at time of creating the object the constructor and destructor are called automatically 
    new_class object_2 ; // at time of creating the object the constructor and destructor are called automatically 
    
    new_class *ptr_obj_2 ;
    ptr_obj_2 = &object_1;// here the object creation is not done so the constructor and destructor are not called  

}