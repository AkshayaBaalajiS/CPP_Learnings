
#include<iostream>
using namespace std ;

class base{
    int private_variable; 
    public:
        base(int args =-1)  // we are having the definition inside the class it is inline 
        {
            private_variable = args ;
            cout<<"@ Constructor 1\n";
        }
        
        ~base();
        
        void display_data();
};
base::~base()  // we are making the definition outside of class so it is not inline 
{
    cout<<"@ Destructor 1\n";
}

void base::display_data()
{
    cout<<"The private data member from class 1 "<< private_variable << " \n"; 
}
class base_1 
{
    int private_variable; 
    public:
        base_1(int args =-1) ; // we are having the definition inside the class it is inline 

        ~base_1() ; 

        void display_data();
        
};
base_1::base_1(int args )
{
    private_variable = args ;
    cout<<"@ Constructor 2\n";
}
base_1::~base_1( )
{
    cout<<"@ Destructor 2\n";
}
void base_1::display_data()
{
    cout<<"The private data member of class 2  "<< private_variable << " \n"; 
}

int main()
{
    base object(12);
    object.display_data();

    base_1 object_1(24);
    object_1.display_data();
}

