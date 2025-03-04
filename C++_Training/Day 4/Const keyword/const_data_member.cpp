#include<iostream>
using namespace std ;

class A
{
    int variable ;
    const int   variable_2 ;
    mutable int variable_1;
    public : 
        A (int args=-1 , int args_1=-1) : variable_2(args) , variable(args_1)  // Initializer - list 
        {
            variable=args;  
        }
        /* The logic cant be applied because it is only for constructor specialiZed 
        compailer checks where it is constructor specialized function or not 
        void change_value(int args ) : variable_2(args) 
        {
            variable_2 = 10;  //the value cant be changed 
        }
        */
        void display ()   
        {
            cout<<"Display function  : " << variable <<"\n";
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