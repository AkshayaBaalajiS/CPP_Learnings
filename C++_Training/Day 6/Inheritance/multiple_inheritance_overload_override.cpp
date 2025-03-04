#include<iostream>
using namespace std ;

class A 
{
    public :
        void  sub(int a=-1 , int b=-1) 
        {
            cout <<"From base and address is " <<this <<"\nA = " << a  << "  B = " << b <<"\nA-B = " << a-b <<"\n";
            cout<<"..............................................................\n";
        }
        void add(double a =-1,double b=-1)  
        {
            cout <<"From base and address is " <<this <<" \nA = " << a  << "  B = " << b <<"\nA+B = " << a+b <<"\n";
            cout<<"..............................................................\n";
        }
};
class AA
{
    public :
        void  mul(int a=-1 , int b=-1) 
        {
            cout <<"From base and address is " <<this <<"\nA = " << a  << "  B = " << b <<"\nA*B = " << a*b <<"\n";
            cout<<"..............................................................\n";
        }
        void add(double a =-1,double b=-1)  
        {
            cout <<"From base and address is " <<this <<" \nA = " << a  << "  B = " << b <<"\nA+B = " << a+b <<"\n";
            cout<<"..............................................................\n";
        }
};

class B : public A , public AA 
{
    public :
        void add(int a )
        {   
            cout <<"From derived and address is " <<this <<"\nA = " << a  <<"\n";
            cout<<"..............................................................\n";
        }
        //over-riding done here instead of the parent class add function derived class fucntion is working 
        void add(double a=-1 ,double b=-1)
        {
            cout <<"From derived and address is " <<this <<"\nA = " << a  << "  B = " << b <<"\nA+B = " << a+b <<"\n";
            cout<<"..............................................................\n";
        };
};

int main()
{

    B object;
    
    //overriding  
    object.add(11,23);

    //overloading
    object.add(11);

    //accessing the parent class member function 
    object.sub(11,23);

    object.mul(5,5);
    
}