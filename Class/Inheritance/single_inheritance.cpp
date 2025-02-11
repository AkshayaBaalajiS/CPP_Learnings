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
        
        void function_to_print_all_datamember()
        {
            cout<<"baseClass void function_to_print_all_datamember ()....\n";
            cout<<"iprivate_variable  = "<<iprivate_variable<<"\n";
            cout<<"fprivate_variable  = "<<fprivate_variable<<"\n";
        }   

        ~baseClass()
        {
            cout<<"baseClass destructor called ..\n";
        }
};

class childClass : public baseClass 
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
            function_to_print_all_datamember();
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