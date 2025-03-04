
#include<iostream>
using namespace std ;

class base{ 
    public:
        int private_variable_1;
        int public_variable_1;
        base(int args =-1 , int args2=-1)  // we are having the definition inside the class it is inline 
        {
            private_variable_1 = args ;
            public_variable_1 = args2 ;
            cout<<"@ Class 1 Constructor \n";
        }
        ~base();
};
base::~base()  // we are making the definition outside of class so it is not inline 
{
    cout<<"@ Class 1 Destructor \n";
}

class base_1 : public base //if the base class has a default constructor but the derived does not have then compailer created the derived default constructor just to make a call to base class default constructor  
{
    int private_variable_2; 

    int private_var1 ;
    int public_var1 ;
    
    public:
        int public_variable_2 ;
        base_1(int args =-1, int args1 =-1) ; // we are having the definition inside the class it is inline 

        ~base_1() ; 

        void display_data();

        void setvalue(int a , int b )
        {
            {
                // base::private_variable_1= a;
                // base::public_variable_1= b;
                
                
                {
                    base object(a,b);
                    // private_var1 =  base::private_variable_1;
                    // public_var1 = base::public_variable_1;
                    private_var1 = object.private_variable_1; //base::private_variable_1 ;
                    public_var1 = object.public_variable_1 ; //::public_variable_1 ;
                    cout<<"---------------------------\n";           
                }
                
            }
        }
        
};

base_1::base_1(int args , int args2 )
{
    private_variable_2 = args ;
    public_variable_2 = args2 ;
    cout<<"@ Class 2 Constructor \n";
}

base_1::~base_1()
{
    cout<<"@ Class 2 Destructor \n";
}

void base_1::display_data()
{
    cout<<"The private data member of class 2  "<< private_variable_2 << " \n";
    cout<<"The public data member of class 2  "<< public_variable_2 << " \n";
    cout<<"The private data member of class 1  " << private_var1 << " \n";   // private data member form class 1 cant be accessed directly so changed to public 
    cout<<"The public data member of class 1  " << public_var1 << " \n";
}

int main()
{
    // base object(12,24); 

    base_1 object_1(13,26);
    cout<<"---------------------------\n";
    object_1.setvalue(12,24);
    cout<<"---------------------------\n";
    object_1.display_data();

    /*
    Though the class 1 object is created only once the class 1 constructor and destructor will be called twice 
    because we have made the class 2 to extend from the class 1  (: public class1) this internally making a object to that class1 
    
    */
}

