#include <stdio.h>
#include <iostream>
using namespace std;
 
namespace ConstantMemberFunction
{
    class cA
    {
        int m_i;    // private member varibale
        mutable int m_j;       // to make this value to be chnaged inside const function
        public:              // default constructor or single parameter constructor
        cA(int arg1 = -1, int arg2 = -1){                // conmstructor with default arguments if no argument passed it is initialized to  -1//
            cout<<"cA::cA.\n";
            m_i = arg1;
            m_j = arg2;
        }
 
        void const display()  {          // here the const is applied to the return type 
        /*
        Now the retunn value from this function accessed from main method or any method cant 
        be any data type other than this (cont datatype ) data type should be of this kind  
        */ 
            cout<<"cA::display: this ="<< this<<"->m_i = "<<m_i<<",m_j = "<< m_j<<"\n";
            m_i = 1234;
            m_j = 1234;
        }
 
       
        ~cA(){       // when an object of cA is destroyed this function will be called
            cout<<"cA::~cA: m_i"<<m_i<<"\n";
            cout<<"cA::~cA: m_J"<<m_j<<"\n";
           
        }
     };
 
    void main()      // this function creates object of a class cA with m_i initialized to 10;//and calls the display function
    {
        cA obj(10,20);          
        cout<<"-----------------------------\n";
        obj.display();
        cout<<"-----------------------------\n";
 
    }
 
}
 
int main()
{
    ConstantMemberFunction::main();
}
