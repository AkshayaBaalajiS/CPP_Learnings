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
            cout << "A = " << a ;
            cout << "  B = " << b ;
            cout << "  C = " << c <<  "\n";
        }
        explicit new_class(int a )  // explicit keyword is a keyword that avoid type converstion that has to be done 
        {
            cout << "A = " << a ;
            cout << "  B = " << b ;
            cout << "  C = " << c <<  "\n";
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
    
    new_class object_1(20);     //constructor overloading  
    
    // new_class object2 = 20 ;   // Constructor overloading using the assignment operator  
    //this cant be done because explicit keyword cant allow the type casting to be done and this require the type casting twice  
    /*
    newclass temp_obj = (new_class)20 ; // here 2 time type casting will be done  
    
    */
    // new_class *ptr_obj_2 ;
    // ptr_obj_2 = &object_1;// here the object creation is not done so the constructor and destructor are not called  


    cout<<"\nThe address of the object from the main " << &object_1  << "\n";
}