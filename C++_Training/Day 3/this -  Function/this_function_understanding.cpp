#include<iostream>
using namespace std ;

class new_class
{
    public :
        int a=10 ;    //new_class::a 
    private : // this cant be accessed outside the class 
        int b=20 ;    //new_class::b
    protected :// this cant be accessed outside the class 
        int c;   //new_class::c  // here we have not initialized the varibale so the value will be garbage 
        //Member functions 
    public :
        void print_all_val ()
        {
            cout << "A = " << a <<  "\n";
            cout << "B = " << b <<  "\n";
            cout << "C = " << c <<  "\n";
        }
        void print_all_val_using_this ()
        {
            cout << "A = " << this->a <<  "\n";
            cout << "B = " << this->b <<  "\n";
            cout << "C = " << this->c <<  "\n";
        }
        void print_address()
        {
            cout<<"This =   "<< this <<"\n"; // in this (this) keyword the object address will be passed 
        }
        /*
            object1.printval();
            g++ :  void __attribute__((thiscall)) print_val(new_class * const this ) 
                            (new_class * const this ) this wont allow the change of the address of the object 
        
        */
        
};

int main()
{
    
    //object creation 

    new_class object_1 ;
    new_class object_2 ;
    
    new_class *ptr_obj_2 ;
    ptr_obj_2 = &object_1;

    // object_1.print_all_val();
    object_1.print_all_val_using_this();

    cout <<"Address of the object_1 is " << &object_1 << "\n";
    cout <<"Address of the object_2 is " << &object_2 << "\n";
    cout<<"\nThe address fetch from fucntion is \n"; 
    cout <<"Object1.print_Address()  " ; 
    object_1.print_address();
    cout <<"Object2.print_Address()  " ; 
    object_2.print_address();
    
   
    

}
/*
 cout<<"Accessing the class varibale / member  with object \n" ;
    cout<<"A = " << object_1.a <<" Sizeof it = " << sizeof(object_1.a)<< "\n" ;
    //the below cant be done because of the scope of the variable in the class
    // cout<<"B = " << object_1.b << " Sizeof it = " << sizeof(object_1.b) << "\n" ;
    // cout<<"C = " << object_1.c << " Sizeof it = " << sizeof(object_1.c) <<"\n" ;
    
    cout<<"Accessing the class varibale / member with pointer  \n" ;
    cout<<"A = " << ptr_obj_2->a << " Sizeof it = " << sizeof(ptr_obj_2->a) << "\n" ;
    //the below cant be done because of the scope of the variable in the class
    // cout<<"B = " << ptr_obj_2->b << " Sizeof it = " << sizeof(ptr_obj_2->b) <<"\n" ;
    // cout<<"C = " << ptr_obj_2->c << " Sizeof it = " << sizeof(ptr_obj_2->c)<<"\n" ;
    


*/