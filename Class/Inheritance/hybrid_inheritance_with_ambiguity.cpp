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
            cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
            cout<<"baseClass void function_to_print_all_datamember ()....\n";
            cout<<"iprivate_variable  = "<<iprivate_variable<<"\n";
            cout<<"fprivate_variable  = "<<fprivate_variable<<"\n";
            cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
        }   

        virtual ~baseClass()
        {
            cout<<"baseClass destructor called ..\n";
        }
};

class childClass_1 : public baseClass
{
    public :
        childClass_1()
        {
            cout<<"childClass_1 constructor called ..\n";
        }
  
        void function_to_print_all_datamember()
        {
            cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
            cout<<"childClass_1 void function_to_print_all()\n";
            function_to_print_all_datamember();

            cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
        }   
        ~childClass_1()
        {
            cout<<"childClass_1 destructor called ..\n";
        }
};

class childClass_2 : public baseClass
{
    public :
        childClass_2()
        {
            cout<<"childClass_2 constructor called ..\n";
        }
  
        void function_to_print_all()
        {
            cout<<"---------------------------------------------------\n";
            cout<<"childClass_2 void function_to_print_all()\n";
            function_to_print_all_datamember();
            cout<<"---------------------------------------------------\n";
        }   
        ~childClass_2()
        {
            cout<<"childClass_2 destructor called ..\n";
        }
};

class childClass_3 : public childClass_2, childClass_1
{
    public :
        childClass_3()
        {
            cout<<"childClass_3 constructor called ..\n";
        }
  
        // void function_to_print_all()
        // {
        //     cout<<"---------------------------------------------------\n";
        //     cout<<"childClass_3 void function_to_print_all()\n";
        //     function_to_print_all_datamember();
        //     cout<<"---------------------------------------------------\n";
        // }   
        ~childClass_3()
        {
            cout<<"childClass_3 destructor called ..\n";
        }
};

int main()
{
    cout<<"This is a program to understand the single inheritance in c++ \n";
    childClass_3 object;
    object.function_to_print_all();
}