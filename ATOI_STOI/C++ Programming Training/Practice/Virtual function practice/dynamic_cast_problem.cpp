#include<iostream>
using namespace std ;
class A 
{
    public :
        virtual void function()
        {
            cout<<"A function  \n";
        }
};
class B : public A
{
    public:
        void function() override 
        {
            cout<<"B function  \n";
        }
};
int main()
{
    A * arr[] = {new A() , new B()};
    arr[0]->function();
    arr[1]->function();
    cout<<"---------------------------------\n";
    for(int i=0;i<2 ; i++)
    {
        B * b_ptr = dynamic_cast<B *>(arr[i]);
        if(b_ptr)
        {
            b_ptr->function();
        }
    }
    cout<<"---------------------------------\n";
    B * ptrrr = new B();
    ptrrr->function();

    B * ptr = (B *) arr[0] ;    //B * = arr[0]
    ptr->function();
    B * ptr_1 = dynamic_cast<B *> (arr[1]) ;
    ptr->function();
    
    cout<<"---------------------------------\n";
    
}