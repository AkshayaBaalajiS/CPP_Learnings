#include <iostream>
using namespace std ;

class new_class
{
    private :
        int variable = 10 ;
        int variable1= 20;
    public : // without public keyword by default it is considered as private 
        int public_var =100;
        void function()
        {
            cout<<"This is a class for testing \n";
        }
        void changevalue (int val )
        {
            variable = val ;
        }
        void printval ()
        {
            cout<<"The value is  "<<variable<<"\n";
            cout<<"The public value is  "<<public_var<<"\n";
            
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
    cout<<"Hello World";
    
    // Object creation 
    new_class object1 ;
    object1.function();
    //try changing the value of the provate data member in class 
    object1.changevalue(20);
    // Accessing the private data member in the class by the pubic member function inside the class  
    object1.printval();
    
    
    //try changing the value of the provate data member in class 
    object1.changevalue(30);
    // Accessing the private data member in the class by the pubic member function inside the class  
    object1.printval();
    
    //sizeof obect = sunm of the sizeof data members in the class 
    cout<<"\nThe size of  object =  " << sizeof(object1)<<"\n";
    
    //accessing the data members with the object 
    object1.public_var = 40 ; 
    object1.printval();
    /*
    new_class object1 ;
    offset object1 : - (0 + 12 ) = -12 

    .operator :
    object1.public_var = 40 ; 
        &object + offset 
        1000  + 8   // 2 = (4+4) for the private variable
        1008 
    
    
    object1.printval();
    g++ :  void __attribute__((thiscall)) print_val(new_class * const this ) 
                            (new_class * const this ) this wont allow the change of the address of the object 
    */
    new_class *ptr = NULL;
    ptr = &object1;
    ptr->public_var = 550;
    ptr->printval();

   /*
   -> operator formula 
        (ptr) + offset(new_vlass::public_var)
        1000 + 8 
        1008
   */

    //this pointer :
    cout << "Address of the object1 :  " << &object1 <<"\n";
    cout << "Address of the pointer to object  :  " << &ptr <<"\n";
    cout << "Address the pointer holds   :  " << ptr <<"\n";

    new_class object2;
    
    object1.print_address();
    object2.print_address(); // this object will be having different address of that fucntion from heap segment  
    ptr->print_address();


    return 0;
}