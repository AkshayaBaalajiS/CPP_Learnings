#include<iostream>
using namespace std ;

class A
{
    public :
        A()
        {cout<<"@ A Constructor \n";}
        
        virtual ~A()
        {cout<<"@ A Destructor \n";}
    
};
class B : public A 
{
    public :
        B()
        {cout<<"@ B Constructor \n";}
        void display();
        ~B()
        {cout<<"@ B Destructor \n";}
    
};
int main()
{
    // B object ; // this will call both class constructor and destructor in order A B     B A 
    A object ; // this will call the A Constructor and A destructor 
    
    cout<<"----------------------------------\n";
    A *ptr =  new B();
    delete ptr ;
    
    cout<<"----------------------------------\n";

}
