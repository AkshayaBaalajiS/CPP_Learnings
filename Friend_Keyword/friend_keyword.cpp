#include<iostream>
using namespace std;

class baseClass
{
    private :
        int privateiVar;
        float privatefVar;
    protected :
        char protectedcVar;
        double protecteddVar;
    public :
        int publicVariable ;
        int publicVariable_1 ;
        baseClass() : privateiVar(0),privatefVar(1.1), protectedcVar('f'), protecteddVar(23.2133), publicVariable(12), publicVariable_1(23)
        {
            cout<<"baseClass constructor called ..\n";
        }        
        friend class childClass;
};


class childClass 
{
    public :
        baseClass object;
        childClass()
        {
            cout<<"childClass constructor called ..\n";
        }   
        void function_to_do_something()
        {
            cout<<"This is the private int variable  " << object.privateiVar << "\n" ;
            cout<<"This is the private float variable  " << object.privatefVar<< "\n" ;
            
            cout<<"This is the protected char variable  " << object.protectedcVar << "\n" ;
            cout<<"This is the protected double variable  " << object.protecteddVar<< "\n" ;
            
            cout<<"This is the public int variable  " << object.publicVariable << "\n" ;
            cout<<"This is the public int variable  " << object.publicVariable_1<< "\n" ;        
        }
};

int main()
{
    cout<<"This is the program for understanding the how friend keyword works \n";
 
    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\n";
    childClass object;
    object.function_to_do_something();
    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n";

    // this is a proof that the friend class data member cant access the class members which is having the friend keyword 
    // cout<<"This is the private variable  " << object.privateVariable << "\n" ;
    // cout<<"This is the private variable  " << object.privateVariable_1<< "\n" ;
    
    // cout<<"This is the protected variable  " << object.protectedVariable << "\n" ;
    // cout<<"This is the protected variable  " << object.protectedVariable_1<< "\n" ;
    
    // the public can be accessed
    cout<<"This is the public variable  " << object.object.publicVariable << "\n" ;
    cout<<"This is the public variable  " << object.object.publicVariable_1<< "\n" ;
    
}

