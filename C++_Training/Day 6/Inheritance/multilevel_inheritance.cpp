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
class derived : public base
{
    int private_variable_2 ;
    public:
        int public_varible_2;
        derived(int args=-1 , int args2=-1) : private_variable_2(args) , public_varible_2(args2) , base(12,24)
        {
            cout<<"@ Class2 Constructor \n";
        }
        int get_value();
        ~derived(){
            cout<<"@ Class2 Destructor \n";
        }
};
int derived::get_value()
{
    return private_variable_2;
}

//class 3
class derived_1 : public derived 
{
    int private_variable_3 ;
    public:
        int public_variable_3 ;
 /*       derived_1(int args=-1 , int args2=-1) : private_variable_3(args) , public_variable_3(args2)// derived::derived()
        {
            derived localObject(11,22);  // constructor is considered as the local object 
            cout<<"@ Class3 Constructor \n";
        }
 */
       derived_1(int args=-1 , int args2=-2, int arg3=-3) : private_variable_3(args) , public_variable_3(args2), derived(11,22)
        {
            cout<<"@ Class3 Constructor \n";
        }
        void display_all_values();
        ~derived_1(){
            cout<<"@ Class3 Destructor \n";
        }
};

void derived_1::display_all_values()
{
    cout<<"Class 3 public variable " << public_variable_3 <<"\n";
    cout<<"Class 3 private variable " << private_variable_3 <<"\n";
    cout<<"................................\n";
    cout<<"Class 2 public variable " << derived::public_varible_2 <<"\n";
    cout<<"Class 2 private variable " << derived::get_value() <<"\n";
    cout<<"................................\n";
    cout<<"Class 1 public varible " << base::public_varible <<"\n";
    cout<<"Class 1 private varible " << base::get_value()<<"\n";
}

int main()
{
    derived_1 object(13,36);
    // derived obj1(23,45);
    object.display_all_values();
}