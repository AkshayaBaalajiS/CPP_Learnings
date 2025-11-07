#include<iostream>
using namespace std;

class baseClass
{
    int iprivate_variable;
    float fprivate_variable;
    public :
        baseClass() : iprivate_variable(1) , fprivate_variable(2.23)
        {
            cout<<"baseClass constructor called ..\n";
        }
        
        void function_to_print_all_datamember_bc()
        {
            cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
            cout<<"baseClass void function_to_print_all_datamember ()....\n";
            cout<<"iprivate_variable  = "<<iprivate_variable<<"\n";
            cout<<"fprivate_variable  = "<<fprivate_variable<<"\n";
            cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
        }   

        ~baseClass()
        {
            cout<<"baseClass destructor called ..\n";
        }
};

class baseClass_1 
{
    public :
        baseClass_1()
        {
            cout<<"baseClass_1 constructor called ..\n";
        }
  
        void function_to_print_all_datamember_bc_1()
        {
            cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
            cout<<"baseClass_1 void function_to_print_all()\n";
            cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
        }   
        ~baseClass_1()
        {
            cout<<"baseClass_1 destructor called ..\n";
        }
};

class childClass : public baseClass, baseClass_1
{
    public :
        childClass()
        {
            cout<<"childClass constructor called ..\n";
        }
  
        void function_to_print_all()
        {
            cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
            cout<<"childClass void function_to_print_all()\n";
            function_to_print_all_datamember_bc();
            function_to_print_all_datamember_bc_1();
            
            cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
        }   
        ~childClass()
        {
            cout<<"childClass destructor called ..\n";
        }
};

int main()
{
    cout<<"This is a program to understand the single inheritance in c++ \n";

    childClass object;
    object.function_to_print_all();


}