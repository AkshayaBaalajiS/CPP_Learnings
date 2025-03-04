#include<iostream>
using namespace std ;
class A 
{
    public :
        int a;
        int b;
        void printt(int a =12, int b=123 ); 
        void display()
        {
            cout<<"A  = " << a << "  B = " << b <<"\n";
        }
};
void A::printt(int a , int b)
{
    this->a=a;
    this->b=b;
}


int main()
{
    A object ;
    object.printt();
    object.display();

}