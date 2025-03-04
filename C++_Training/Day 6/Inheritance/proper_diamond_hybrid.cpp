#include<iostream>
using namespace std ;

struct A  {  //4 bytes 
    int public_variable; 
    A()
    {
        cout<<"@ A Constructor  " << this << "\n";
    }
    ~A()
    {
        cout<<"@ A Destructor  " << this << "\n";
    }
};

//hierarchical 
struct B  :  A { // 8 bytes 
    int public_variable_1;
    B()
    {
        cout<<"@ B Constructor  " << this << "\n";
    }
    ~B()
    {
        cout<<"@ B Destructor  " << this << "\n";
    }
};
struct C :   A { // 8 bytes 
    int public_variable_2;
    C()
    {
        cout<<"@ C Constructor  " << this << "\n";
    }
    ~C()
    {
        cout<<"@ C Destructor  " << this << "\n";
    }
};

// multiple inheritance 
struct D  : B , C{ // 20 bytes 
    int public_variable_3;
    D()
    {
        cout<<"@ D Constructor  " << this << "\n";
    }
    ~D()
    {
        cout<<"@ D Destructor  " << this << "\n";
    }
};


void sizes()
{
    cout <<"Size of struct A " << sizeof(A) << "\n";    //4
    cout <<"Size of struct B " << sizeof(B) << "\n";  //8 
    cout <<"Size of struct C " << sizeof(C) << "\n"; //8
    cout <<"Size of struct D " << sizeof(D) << "\n";   //20
}

int main()
{
    // sizes();  
    D object ;



}
