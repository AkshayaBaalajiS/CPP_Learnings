#include<iostream>
using namespace std ;

class sampleClass{
    int a ;
    public :
        explicit sampleClass()
        {
            cout<<"This is a default constructor for sampleClass..\n";
        }
        explicit sampleClass(int args)
        {
            cout<<"This is a single parameterized constructor for sampleClass \n";
        } 
        void function_to_do_something(int & a )
        // void function_to_do_something(int & a )   // this is a funciton created to prove tht explict cant be applied on the normal function
        {
            cout<<"The value typecasted from int : " << a << " to double and the result is : " << double(a)<<endl;
        }

        ~sampleClass()
        {
            cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
            cout<<"The Destructor called all resource of the class are deleted ..\n";
        }
};

/*
PROGRAM TO UNDERSTAND THE EXPLICIT CANT BE USED ON THE FUNCTIONS OUTSIDE OF THE CLASS IT CAN BE APPLIED ONLY ON THE CONSTRUCTOROF A CLASS 
*/
// explicit void function_to_do_something(int & a )
void function_to_do_something(int & a )   // this is a funciton created to prove tht explict cant be applied on the normal function
{
    cout<<"The value typecSted from int : " << a << " to double and the result is : " << double(a)<<endl;
}

int main()
{
    cout<<"This is a program to understand the explicit keyword cant be applied on normal functions ...\n";

    int iVar = 12;
    // how not to do explicit 
    function_to_do_something(iVar);

    // real example of explicit 
    sampleClass object ; // no error 
    sampleClass * ptr = new sampleClass(); // no error (that is no type conversion) 

    // sampleClass object_1 = 10 ; // now error because of the type conversion // here the int value 10 converted to sampleClass type 
    // if the constructor is like sampleClass(int args) there wont be any issue 

}