#include <iostream>
using namespace std;

class simpleClass
{
    private : 
        int iVariable1;
        int iVariable2;
        
        float fVariable1;
        float fVariable2;
    public :
        simpleClass() : iVariable1(0) , iVariable2(0) , fVariable1(0.0) , fVariable2(0.0)
        {
            cout<<"This is the constructor called by default and variable are initialized with intializer list \n";
        }
        int iVariable3 ;

        static int iVariable4 ;

        int getter_iv1()
        {
            return iVariable1;
        }

        static int sGetter_iv1()
        {
            // return iVariable1;  inside static only the static member can be accessed 
            return iVariable4;
        }

        int getter_iv2()
        {
            return iVariable2;
        }
        float getter_fv1()
        {
            return fVariable1;
        }
        float getter_fv2()
        {
            return fVariable2;
        }
        
        ~simpleClass()
        {
            cout<<"Destructor called for the class simpleClass\n ";
        }

};

int simpleClass::iVariable4 = 1002;

int main()
{
    cout<<"This is a program to understand how to access the datamembers of the class ..\n";

    // we are using the getter to access the private variable 
    cout<<"Now the data member accessed through Class  \n";
    /*cannot call member function ‘int simpleClass::getter_iv2()’ without object*/
    // cout<<"Integer Variable 1 : " << simpleClass::getter_iv1() << "\n";
    // cout<<"Integer Variable 2 : " << simpleClass::getter_iv2() << "\n";
    // cout<<"Float Variable 1 : " << simpleClass::getter_fv1()<< "\n";
    // cout<<"Float Variable 2 : " << simpleClass::getter_iv2() << "\n";
    
    /*Only the static data member and static member function can be accessed through the class and scope resolution */
    // cout<<"Integer Variable 3 : " << simpleClass::iVariable3 ; // this is a non static data member so cant be accessed 
    cout<<"Integer Variable 4 : " << simpleClass::iVariable4 <<endl; // this is through static variable 
    cout<<"Integer Variable 4 : " << simpleClass::sGetter_iv1() <<endl;  // this is through static function 
    
    cout<<endl<<"------------------------------------------------------\n";


    simpleClass object ;
    cout<<"Now the data member accessed through the object ..\n";
    cout<<"Integer Variable 1 : " << object.getter_iv1() << "\n";
    cout<<"Integer Variable 2 : " << object.getter_iv2() << "\n";
    cout<<"Float Variable 1 : " << object.getter_fv1()<< "\n";
    cout<<"Float Variable 2 : " << object.getter_iv2() << "\n";
    // cout<<"Integer Variable 4 : " << object.sGetter_iv1() << "\n"; // this cant be done because this is a static function but the obj is not static 
    cout<<"Integer Variable 3 : " << object.iVariable3 ; 
    // cout<<"Integer Variable 4 : " << object.iVariable4 ; // this cant be done because the variable is static but the obj is not static 
    cout<<endl<<"------------------------------------------------------\n";




    simpleClass * ptr =  new simpleClass;
    cout<<"Now the data member accessed through the pointer ..\n";
    cout<<"Integer Variable 1 : " << ptr->getter_iv1() << "\n";
    cout<<"Integer Variable 2 : " << ptr->getter_iv2() << "\n";
    cout<<"Float Variable 1 : " << ptr->getter_fv1()<< "\n";
    cout<<"Float Variable 2 : " << ptr->getter_iv2() << "\n";
    cout<<"Integer Variable 3 : " << ptr->iVariable3 ; 
    // cout<<"Integer Variable 4 : " << ptr->iVariable4 ;  // this cant be done because the variable is static but the obj is not static 
    // cout<<"Integer Variable 4 : " << object.sGetter_iv1() << "\n"; // this cant be done because this is a static function but the obj is not static 
    cout<<endl<<"------------------------------------------------------\n";


}