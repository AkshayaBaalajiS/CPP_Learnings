#include<iostream>
using namespace std ;
//Class 1 
class base
{
    int private_variable = 20;
    public :
        int public_varible =10;
        base(int args=-1 , int args2=-1 ){
            private_variable = args ;
            public_varible = args2 ;
            cout<<"@ Class1 Constructor \n";
        }
        inline int get_value() ;
        ~base(){
            cout<<"@ Class1 Destructor \n";
        }
};
int base::get_value()
{
    return private_variable;
}
//class 2
class base_1 
{
    int private_variable_2 ;
    public:
        int public_variable_2;
        base_1(int args=-1 , int args2=-1) : private_variable_2(args) , public_variable_2(args2) 
        {
            cout<<"@ Class2 Constructor \n";
        }
        int get_value();
        ~base_1(){
            cout<<"@ Class2 Destructor \n";
        }
};
int base_1::get_value()
{
    return private_variable_2;
}

//class 3
class derived : public base , public base_1
{
    int private_variable_3 ;
    public:
        int public_variable_3 ;
 /*       derived(int args=-1 , int args2=-1) : private_variable_3(args) , public_variable_3(args2)// base_1::base_1()
        {
            base_1 localObject(11,22);  // constructor is considered as the local object 
            cout<<"@ Class3 Constructor \n";
        }
 */
        derived(int args=-1 , int args2=-2, int arg3=-3) : private_variable_3(args) , public_variable_3(args2), base(11,22) , base_1(12,24)
        {
            cout<<"@ Class3 Constructor \n";
        }
        void display_all_values();
        ~derived(){
            cout<<"@ Class3 Destructor \n";
        }
};

void derived::display_all_values()
{
    cout<<"derived public variable " << public_variable_3 <<"\n";
    cout<<"derived private variable " << private_variable_3 <<"\n";
    cout<<"................................\n";
    cout<<"base_1 public variable " <<base_1::public_variable_2 <<"\n";
    cout<<"base_1 private variable " << base_1::get_value() <<"\n";
    cout<<"................................\n";
    cout<<"base public varible " << base::public_varible <<"\n";
    cout<<"base private varible " << base::get_value()<<"\n";
}

int main()
{
    derived object(12,24);
    object.display_all_values();
}
