#include<iostream>
using namespace std;

class simpleClass
{
    int privateVariable_1 ;
    int privateVariable_2 ;
    int privateVariable_3 ;
    int privateVariable_4 ;
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

        simpleClass(int arg1, int arg2, int arg3, int arg4 )
        {
            cout<<"This simpleClass(int arg1, int arg2, int arg3, int arg4 ) constructor called \n";
            privateVariable_1=arg1;
            privateVariable_2=arg2;
            privateVariable_3=arg3;
            privateVariable_4=arg4;
            
        }

        simpleClass(simpleClass & ref )
        {
            cout<<"This simpleClass(simpleClass & ref ) copy constructor called \n";
            privateVariable_1=ref.privateVariable_1;
            privateVariable_2=ref.privateVariable_2;
            privateVariable_3=ref.privateVariable_3;
            privateVariable_4=ref.privateVariable_4;
        }

        simpleClass(simpleClass && ref)
        {
            cout<<"This simpleClass(simpleClass && ref ) move constructor called \n";
            privateVariable_1=ref.privateVariable_1;
            privateVariable_2=ref.privateVariable_2;
            privateVariable_3=ref.privateVariable_3;
            privateVariable_4=ref.privateVariable_4;
        }   

        ~simpleClass()
        {
            cout<<"The simpleClass destructor called ..\n";
        }

};
int main()
{
    cout<<"This is the program to understand the copy and move constructor ..\n";

    simpleClass object ; // this will call the default constructor 

    simpleClass * ptr = new simpleClass; // this will call the default constructor 

    simpleClass object_2(10,20); // this will call the parameterized constructor 

    simpleClass * ptr_1= new simpleClass(10,20,30,40); // this will call the parameterized constructor 

    simpleClass object_3 = object; // copy constructor called 
    simpleClass object_3_1(object); // copy constructor called 
    
    simpleClass object_4 = move(object_2); // move constructor called 
    simpleClass object_4_1(move(object_2)); // move constructor called 


}