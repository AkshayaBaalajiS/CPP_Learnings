#include<iostream>
using namespace std ;

class A
{
    int variable ;
    mutable int variable_1;
    public : 
        A (int args=-1)
        {
            variable=args;  
        }
        void display () const   // void __thiscall display (const A * const this )
        {
            cout<<"Display function  : " << variable <<"\n";
            // variable = 10;  the value cant be changed 
            display_1();
            //display_2() this cant be called because it is not the const member function 
        }
        void display_1() const {
            cout<<"This is another constant member function which can be called \n"; 
            variable_1 = 78 ;
            /*
            int & variable_1 =const_cast <int &> (this->variable_1) ; // const_cast is a funciton that removes the constness of a variable  
            */
            cout<<"In this constant member fucntion the value of the mutable variable is changed "<< variable_1 <<"\n"; 
            
        }
        void display_2() {
            cout<<"This is a member function which cant be called \n"; 
        }
        
        ~A()
        {
            cout<<"The value of the variable at time of destructor " << variable << "\n";
            cout<<"The value of the variable_1 at time of destructor " << variable_1 << "\n";
            
        }
};

int main() {
    A object(23);
    object.display();

   return 0;
}