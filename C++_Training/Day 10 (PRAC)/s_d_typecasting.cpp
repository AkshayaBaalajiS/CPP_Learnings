#include <iostream>
using namespace std ;

class A 
{
  public :
    void show()
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
    // A object_1 ; 
    B object ;
    A object_a ;
    
    // A * ptr = &object  ;
    // ptr->show();
    
    // B & ref_b = object;
    // ref_b.show_a();
    // ref_b.show_b();
    
    //type casting :
    
    A * ptr = dynamic_cast <A *> (&object);
    
    // down to up static cast     
    // B * ptr_1 = static_cast <B*> (&object_a);
    
    return 0;
}