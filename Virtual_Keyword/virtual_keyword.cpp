#include<iostream>
using namespace std;

class baseClass
{
    public :
        baseClass()
        {
            cout<<"baseClass constructor called \n";
        }

        virtual void display_function()
        {
            cout<<"This is baseClass display function\n";
        }

        
        ~baseClass()
        {
            cout<<"baseClass destructor called \n";
        }
};

class childClass :  public baseClass
{
    public :
        childClass()
        {
            cout<<"childClass constructor called \n";
        }

        void display_function()
        {
            cout<<"This is childClass display function\n";
        }
        
        
        ~childClass()
        {
            cout<<"childClass destructor called \n";
        }
};


int main()
{
    cout<<"This is a program to understand the virtual keyword in C++\n";

    baseClass b_object;
    b_object.display_function();
    
    cout<<"========================================================\n";

    childClass c_object;
    c_object.display_function();
    
    cout<<"========================================================\n";

    baseClass * b_ptr = new baseClass();
    childClass * c_ptr = new childClass();

    cout<<"========================================================\n";

    b_ptr= &c_object;

    b_ptr->display_function(); // here the derived class function will be called 

    cout<<"========================================================\n";


    c_ptr->display_function(); // here the derived class function will be called 

    cout<<"========================================================\n";


    baseClass * b_ptr_1 = new childClass();
   
    cout<<"========================================================\n";
    
    b_ptr_1->display_function(); // this will call the dereived class function 

    cout<<"========================================================\n";

    baseClass * b_ptr_3 = new baseClass();

    cout<<"========================================================\n";

    b_ptr_3->display_function(); // base class function will be called 

    cout<<"========================================================\n";


}