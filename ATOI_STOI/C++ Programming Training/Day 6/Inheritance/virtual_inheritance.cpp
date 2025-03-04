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
struct B  : virtual  A {  
    /* void * m_vptr ;   */ // at compile time so size is sizeof(A) + sizeof(m_vptr) + sizeof(public_variable_1)  4 + 8 + 4 = 16
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
struct C :  virtual A { 
    /* void * m_vptr ;   */ // at compile time so size is sizeof(A) + sizeof(m_vptr) + sizeof(public_variable_2)  4 + 8 + 4 = 16
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
struct D  :public  B , C{ 
    /* void * m_vptr ;   */ // at compile time so size is sizeof(B) + sizeof(C) + sizeof(m_vptr) + sizeof(public_variable_3)  12 + 12 + 4 = 16
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
    cout <<"Size of struct B " << sizeof(B) << "\n";  //16 
    cout <<"Size of struct C " << sizeof(C) << "\n"; //16
    cout <<"Size of struct D " << sizeof(D) << "\n";  //32
}

int main()
{
    sizes();  
    // D object ;
}
/*
Size of struct A 4
Size of struct B 16
Size of struct C 16
Size of struct D 32
*/