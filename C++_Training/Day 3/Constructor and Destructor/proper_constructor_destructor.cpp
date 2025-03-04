#include<iostream>
using namespace std ;

class new_class
{
    int a =100;
    int b =100;
    int c =100;

    public :
        new_class()
        {
            cout << "Address of the object from construtor " << this << "\n";
            cout<<"Automatically get called at time of creating a object " <<"\n ";
            cout << "A = " << a <<  "\n";
            cout << "B = " << b <<  "\n";
            cout << "C = " << c <<  "\n";
        }
        ~new_class()
        {
            cout << "\nAddress of the object from destrucor " << this << "\n";
            cout<<"Resource get deallocated and the value will be garbage \n";
            cout << "A = " << a <<  "\n";
            cout << "B = " << b <<  "\n";
            cout << "C = " << c <<  "\n";
        }
   
};

int main()
{
    
    // object creation 
    new_class object_1 ;// at time of creating the object the constructor and destructor are called automatically 
    
    new_class *ptr_obj_2 ;
    ptr_obj_2 = &object_1;// here the object creation is not done so the constructor and destructor are not called  

    cout<<"The address of the object from the main " << &object_1  << "\n";

    
   
    

}