#include<iostream>
using namespace std ;
class A 
{
    public :
        virtual void function()
        {
            cout<<"A function  \n";
        }
        void function_1()
        {
            cout<<"A function_1  \n";
        }
        void function_2()
        {
            cout<<"A function_2  \n";
        }
        
};
class B : public A
{
    public:
        void function() override 
        {
            cout<<"B function  \n";
        }
        void function_1()
        {
            cout<<"B function_1  \n";
        }
        void function_3()
        {
            cout<<"B function_3  \n";
        }
        

};
int main()
{
    A a_object ;
    B b_object;
    cout<<"------------------\n";
    a_object.function();  //A function 
    b_object.function(); // B function
    cout<<"------------------\n";
    A * a_ptr = &b_object ;  // A function and only can access the A class member functions   
    a_ptr->function();
    a_ptr->function_2();  
    cout<<"------------------\n";
    B * b_ptr = &b_object ; // this can access every class member function 
    b_ptr->function();
    b_ptr->function_2();
    cout<<"------------------\n";
    cout<<"\nReference : \n";
    A & a_ref = b_object; // this can only access class A member functions 
    a_ref.function();
    a_ref.function_2();
    cout<<"------------------\n";
    B & b_ref = b_object; // this can only access class A member functions 
    b_ref.function_2();
    b_ref.function_3();
    cout<<"------------------\n";

    B & bb_ref = *b_ptr ; // this can access every class member functions 
    bb_ref.function_3();
    bb_ref.function();
    bb_ref.function_2();

    cout<<"------------------\n";
    A & aa_ref = *b_ptr ; // this can access only A class member fucntion  
    // aa_ref.function_3();  cant be done because it is a member fucntion of b class 
    aa_ref.function();
    aa_ref.function_2();

    cout<<"------------------\n";
    A aa_object = b_object;
    aa_object.function();
        



}