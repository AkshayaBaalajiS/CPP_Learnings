#include<iostream>
using namespace std ;
class A
{
    public :
        A()
        {
            cout<<"@ A Constructor \n";
        }

        void function()
        {
            cout<<"A :: function    \n";
        }


        ~A()
        {
            cout<<"@ A Destructor \n";
        }
};

class B : public virtual A 
{
    public :
        B()
        {
            cout<<"@ B Constructor \n";
        }

        void function()
        {
            cout<<"B :: function    \n";
        }

        ~B()
        {
            cout<<"@ B Destructor \n";
        }
};
class C : public virtual A {
    public:
        C() 
        {
            cout << "@ C Constructor \n";
        }

        void function() 
        {
            cout << "C :: function \n";
        }

        ~C() 
        {
            cout << "@ C Destructor \n";
        }
};

//There is no ambiguity till now 
//From below the ambiguity occurs 

class D : public  B , public C  {
    public:
        D() 
        {
            cout << "@ D Constructor \n";
        }

        void function() 
        {
            cout << "C :: function \n";
        }

        ~D() 
        {
            cout << "@ D Destructor \n";
        }
};

int main()
{
    
    // B b_object ;
    
    // cout<<"---------------------------\n";
    // b_object.function();
    // cout<<"...........................\n";
    // b_object.A::function();
    // cout<<"---------------------------\n";
    
    // C c_object ;
    
    // cout<<"---------------------------\n";
    // c_object.function();
    // cout<<"...........................\n";
    // c_object.A::function();
    // cout<<"---------------------------\n";

    //the before stmt have no problem till now 

    D d_object ;
    
    cout<<"---------------------------\n";
    d_object.function();
    cout<<"...........................\n";
    // d_object.A::function();   // this cant be accessed from D even B and C are derived of A  due to ambiguity 
    // in detail the compailer wont know through which class it can access A  (through B or C )
    cout<<"---------------------------\n";


}
