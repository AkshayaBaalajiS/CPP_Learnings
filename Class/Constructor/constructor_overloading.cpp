#include<iostream>
using namespace std;

class simpleClass
{
    int privateVariable_1 ;
    int privateVariable_2 ;
    float privateVariable_3 ;
    float privateVariable_4 ;
    public :
        simpleClass() : privateVariable_1(1), privateVariable_2(2), privateVariable_3(3), privateVariable_4(4)
        {
            cout<<"This is the default constructor for the class simpleClass \n";
        }
        
        simpleClass(int arg1, int arg2 )
        {
            cout<<"This simpleClass(int arg1, int arg2 ) constructor called \n";
            privateVariable_1=arg1;
            privateVariable_2=arg2;   
        }

        simpleClass(double arg1, double arg2 )
        {
            cout<<"This simpleClass(double arg1, double arg2 ) constructor called \n";
            privateVariable_3=arg1;
            privateVariable_4=arg2;
        }

        // there is no destructor_overloading in c++
        ~simpleClass()
        {
            cout<<"The destructor for simpleClass is the called \n";
        }

};
int main()
{
    cout<<"This is the program to understand the copy and move constructor ..\n";

    simpleClass object ; // this will call the default constructor 

    simpleClass * ptr = new simpleClass; // this will call the default constructor 

    simpleClass object_2(10,20); // this will call the parameterized constructor 

    simpleClass object_3(34.45,56.56); // this will overload the constructor  
    

}