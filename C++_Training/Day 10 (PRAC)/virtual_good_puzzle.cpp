/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std ;

class A 
{
  public :
    virtual void show()
    {
        cout<<"A\n";
    }
    ~A()
    {
        cout<<"@ A Destructor \n";
    }
    
};

class B  : public A
{
  public :
    void show()
    {
        cout<<"B\n";
    }
    ~B()
    {
        cout<<"@  B Destructor \n";
    }
};

int main()
{
    cout<<"Hello World\n";
    
    B object ;
    
    A object_1 = object ;
    cout<<"-----------------\n";
    object_1.show();
    cout<<"----------------\n";
    
    return 0;
}