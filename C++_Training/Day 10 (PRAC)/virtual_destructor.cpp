/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std ;

class A 
{
  public :
    A()
    {
        cout<<"@ A Constructor \n";
    }
    virtual void show()
    {
        cout<<"A\n";
    }
    virtual ~A()
    {
        cout<<"@ A Destructor \n";
    }
    
};

class B  : public A
{
    
  public :
    B()
    {
        cout<<"@ B Constructor \n";
    }
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
    A *ptr_1 = new B() ;
    cout<<"-----------------\n";
    ptr_1->show();
    cout<<"----------------\n";
    delete ptr_1;
    cout<<"----------------\n";
    
    return 0;
}