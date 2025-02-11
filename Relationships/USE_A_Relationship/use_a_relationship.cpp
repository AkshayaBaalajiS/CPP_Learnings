// composition or aggregation  
// mean object has a reference with another object or contains another object  
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

class childClass 
{

    public :
        childClass() 
        {
            cout<<"childClass constructor called ..\n";
        }
     
        void function_to_print_all(baseClass * ptr )   // uses a relation 
        {
            cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
            cout<<"childClass void function_to_print_all()\n";
            ptr->function_to_print_all_datamember();
            cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
        }   
        ~childClass()
        {
            cout<<"childClass destructor called ..\n";
        }
};




int main()
{
    cout<<"This is a program to demonstrate the Has a Relationship in c++ \n";
    childClass object;
    baseClass bObject ;
    object.function_to_print_all(&bObject);
}