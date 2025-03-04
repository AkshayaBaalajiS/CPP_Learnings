#include<iostream>
using namespace std ;

class base
{
    int private_variable = 24;
    public :
        int public_varible =12;
        base(){
            cout<<"@ Class1 Constructor \n";
        }
        inline int get_value() ;
        // void display();
        ~base(){
            cout<<"@ Class1 Destructor \n";
        }
};
int base::get_value()
{
    return private_variable;
}
class derived : public base 
{
    int private_varible_2 ;
    public:
        int public_varible_2;
        derived(int args=-1 , int args2=-1) : private_varible_2(args) , public_varible_2(args2)
        {
            cout<<"@ Class2 Constructor \n";
        }
        void display_all_values();
        
        ~derived(){
            cout<<"@ Class2 Destructor \n";
        }
};
void derived::display_all_values()
{
    cout<<"Class 2 public variable " << public_varible_2 <<"\n";
    cout<<"Class 2 private variable " << private_varible_2 <<"\n";
    cout<<"................................\n";
    cout<<"Class 1 public varible " << base::public_varible <<"\n";
    cout<<"Class 1 private varible " << base::get_value()<<"\n";
}

int main()
{
    derived object(36,13);
    object.display_all_values();
    
}