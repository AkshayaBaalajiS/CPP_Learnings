#include<iostream>
using namespace std ;

class A
{
    int variable ;
    int variable_1 ;
    public : 
        // A (int variable=-1 , int variable_1=-1)
        // {
        //     variable=variable;     // op for variable is garblage 
        //     this->variable_1 = variable_1;  // this keyword helps to set the data member 

        // }
        
        A (int variable=-1 , int variable_1=-1) : variable(variable) , variable_1(variable_1)  
        // the left side is the data member of the class and right side is the local data member   
        { 

        }
        
        ~A()
        {
            cout<<"The value of the variable at time of destructor " << variable << "\n";
            cout<<"The value of the variable_1 at time of destructor " << variable_1 << "\n";
            
        }
};

int main() {
    A object(324,34);

   return 0;
}