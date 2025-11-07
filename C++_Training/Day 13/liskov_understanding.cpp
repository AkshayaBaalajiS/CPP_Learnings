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
    void print()
    {
        cout<<"Poda AB " << "\n";
    }
};
class B : public A 
{
  public :
    void print()
    {
        cout<<"Poda Ethi " << "\n";
    }
};
int main()
{
    cout<<"Hello World\n";
    B object ;
    A object_1;
    // A a_object = object ; //can be done 
    // B b_object = a_object ;  //cant be done 
    
    // A * ptr = new B();  // can be done 
    // B * b_ptr = new A(); //cant be done 
    
    A * ptr = &object; // can be done 
    // B * ptr_1 =  & object_1 ; // cant be done
    ptr->print();
    
    // B * ptr_1 = a_object ; //cant be done 
    // ptr->print();
    return 0;
}

 