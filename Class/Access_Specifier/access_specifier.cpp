#include<iostream>
using namespace std;

class baseClass
{
    private :
        int piVar;
        float pfVar;
    protected :
        char pcVar;
        double pdVar;
    public :
        int publicVariable ;
        int publicVariable_1 ;
        baseClass() : piVar(0),pfVar(1.1), pcVar('f'), pdVar(23.2133), publicVariable(12), publicVariable_1(23)
        {
            cout<<"baseClass constructor called ..\n";
        }        
};


class childClass : public baseClass
{
    public :
        childClass()
        {
            cout<<"childClass constructor called ..\n";
        }   
        void function_to_do_something()
        {
            cout<<"This is a child class function to print the data member of parent class ..\n";
            // this cant be done because of the private scope 
            // cout<<"Private int variable : " << piVar<<endl;
            // cout<<"Private float variable : " << pfVar<<endl;

            cout<<"Protected char variable : " << pcVar<<endl;
            cout<<"Protected double variable : " << pdVar<<endl;

            cout<<"Public int variable "<< publicVariable<<endl ;
            cout<<"Public int variable "<< publicVariable_1<<endl ;
        
        }
};

// class childClass_1 : public baseClass
class childClass_1 : protected baseClass
{
    public :
        childClass_1()
        {
            cout<<"childClass_1 constructor called ..\n";
        }   
        void function_to_do_something()
        {
            cout<<"This is a child class 2 function to print the data member of parent class ..\n";
            // this cant be done because of the private scope 
            // cout<<"Private int variable : " << piVar<<endl;
            // cout<<"Private float variable : " << pfVar<<endl;

            cout<<"Protected char variable : " << pcVar<<endl;
            cout<<"Protected double variable : " << pdVar<<endl;

            cout<<"Public int variable "<< publicVariable<<endl ;
            cout<<"Public int variable "<< publicVariable_1<<endl ;
        
        }
};

class childClass_2 : private baseClass
{
    public :
        childClass_2()
        {
            cout<<"childClass_2 constructor called ..\n";
        }   
        void function_to_do_something()
        {
            cout<<"This is a child class 2 function to print the data member of parent class ..\n";
            // this cant be done because of the private scope 
            // cout<<"Private int variable : " << piVar<<endl;
            // cout<<"Private float variable : " << pfVar<<endl;

            cout<<"Protected char variable : " << pcVar<<endl;
            cout<<"Protected double variable : " << pdVar<<endl;

            cout<<"Public int variable "<< publicVariable<<endl ;
            cout<<"Public int variable "<< publicVariable_1<<endl ;
        
        }
};

int main()
{
    cout<<"This is the program for understanding the access specifier and how the access specifier on extends works \n";
    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n";
    childClass object;
    object.function_to_do_something();
    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n";

    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\n";
    childClass_1 object_1;
    object_1.function_to_do_something();
    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n";

    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\n";
    childClass_2 object_2;
    object_2.function_to_do_something();
    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n";

    // The object is the child class object which extends the parent class with public as access specifier 
    // This is the reason why the variable is accessible 
    cout<<"This is the public variable  " << object.publicVariable << "\n" ;
    cout<<"This is the public variable  " << object.publicVariable_1<< "\n" ;
    
    // The object is the child class object which extends the parent class with protected as access specifier 
    // This is the reason why the variable is not accessible 
    // cout<<"This is the public variable  " << object_1.publicVariable << "\n" ;
    // cout<<"This is the public variable  " << object_1.publicVariable_1<< "\n" ;
    
    // The object is the child class object which extends the parent class with private as access specifier 
    // This is the reason why the variable is not accessible 
    // cout<<"This is the public variable  " << object_2.publicVariable << "\n" ;
    // cout<<"This is the public variable  " << object_2.publicVariable_1<< "\n" ;
    
}