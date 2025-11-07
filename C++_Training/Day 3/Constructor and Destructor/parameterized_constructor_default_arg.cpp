#include<iostream>

using namespace std ;

class new_class
{
    public :
        new_class(int a =-1 ,int b=-2,int c=-3)  //this can run even on a default , single , two , three parameterized constructor 
        {
            cout<<"A = " << a << "      B = " << b << "     C = " << c <<"\n";
        }
};


int main()
{   
    //Default parameter 
    new_class c_object1 ;
    //simgle parameterized constructor 
    new_class c_object2(100);
    //parameterized constructor 
    new_class c_object3(100,343);
    //simgle parameterized constructor 
    new_class c_object4(12,54,34);
    

}