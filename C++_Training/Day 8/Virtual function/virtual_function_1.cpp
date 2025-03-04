#include<iostream>
using namespace std ;
class A
{
    public:
        virtual void vfun()
        {
            cout<<"A class Virtual function \n";
        }
};
class B : public A
{
    public:
        void vfun() override  
        {
            cout<<"B class Overriden Function \n";
        }
};

int main()
{
    A a_object ;
    a_object.vfun();
    cout<<"----------------------------------\n";
    B b_object ;
    b_object.vfun();
    cout<<"----------------------------------\n";
    A a_object_1 = b_object ; // calling A::vfun why ?
    a_object_1.vfun();
    cout<<"----------------------------------\n";
    A * ptr = NULL ;
    ptr = &b_object ;
    ptr->vfun();
    cout<<"----------------------------------\n";
    A * ptr_1 = &a_object;
    ptr_1->vfun();
    cout<<"----------------------------------\n";
    A & ptr_1_1 = a_object;
    ptr_1_1.vfun();
    cout<<"----------------------------------\n";
    A & ptr_1_2 = b_object;
    ptr_1_2.vfun();
    cout<<"----------------------------------\n";
    /*The below cant be done because of typassting from A to B is to be done 
    B b_object_1 = a_object ;
    b_object.vfun();
    */
    cout<<"----------------------------------\n";
    /*The below is a error because the B* cant be assigned with A* 
    B * ptr_2 = NULL ;
    ptr_2 = &a_object ;
    ptr->vfun();
    */
    cout<<"----------------------------------\n";
    B * ptr_22 = &b_object;
    ptr_22->vfun();
    cout<<"----------------------------------\n";
    /* invalid initialization of reference of type 'B&' from expression of type 'A'
    B & ptr_2_1 = a_object;
    ptr_2_1.vfun();
    cout<<"----------------------------------\n";
    */
    B & ptr_2_2 = b_object;
    ptr_2_2.vfun();
    cout<<"----------------------------------\n";
    
}


    // A a_object_1 =  b_object;
    // a_object_1.vfun();
    // cout<<"----------------------------------\n";