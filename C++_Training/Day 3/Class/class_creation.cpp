#include<iostream>
using namespace std ;

//Here it occupies 1 byte we are wasting it to get the base address of it 
class empty_class{};
/*
The space is allocated when the class is instantiated, 
so 1 byte is allocated by the compiler to an object of an empty class for its unique address identification. 
*/

class new_class
{
    public :
        int a=10 ;    //new_class::a 
    private : // this cant be accessed outside the class 
        int b=20 ;    //new_class::b
    protected :// this cant be accessed outside the class 
        int c=30;   //new_class::c
    /*
    SOM - Simple Object Model 
    When there are more data member and the member function : 
        the performance will not be good 
        It need to each to base address and then HEAP and then to the code segment (for fucntion)
        For accessing the single variable we need atleast 5 bytes 4 for the user-stack and 1 for the Heap 

    TDL - Table Driven Model 
        Each object will be having 2 pointers 1. Data pointer and 2. Member pointer which is from the Heap segment 
        So when we try to add any new data member it will be only added in the heap segment not in the user-stack segment    
    
    C++ pbject model - Stone Stroke model 


    */
        //Member functions 
        void func_1() //new_class::func_1   
        {
            cout<<"A = " << a <<" Sizeof it = " << sizeof(a)<< "\n" ;
        }
        void func_2() //new_class::func_1   
        {
            cout<<"A = " << b <<" Sizeof it = " << sizeof(b)<< "\n" ;
        }
        
};

int main()
{
    
    //object creation 
    empty_class e_object1;
    cout<<"Empty class size : "<<sizeof(e_object1) << "\n";

    new_class object_1 ;

    new_class *ptr_obj_2 ;
    ptr_obj_2 = &object_1;



    cout<<"Accessing the class varibale / member  with object \n" ;
    cout<<"A = " << object_1.a <<" Sizeof it = " << sizeof(object_1.a)<< "\n" ;
    // cout<<"B = " << object_1.b << " Sizeof it = " << sizeof(object_1.b) << "\n" ;
    // cout<<"C = " << object_1.c << " Sizeof it = " << sizeof(object_1.c) <<"\n" ;
    
    cout<<"Accessing the class varibale / member with pointer  \n" ;
    cout<<"A = " << ptr_obj_2->a << " Sizeof it = " << sizeof(ptr_obj_2->a) << "\n" ;
    // cout<<"B = " << ptr_obj_2->b << " Sizeof it = " << sizeof(ptr_obj_2->b) <<"\n" ;
    // cout<<"C = " << ptr_obj_2->c << " Sizeof it = " << sizeof(ptr_obj_2->c)<<"\n" ;

}