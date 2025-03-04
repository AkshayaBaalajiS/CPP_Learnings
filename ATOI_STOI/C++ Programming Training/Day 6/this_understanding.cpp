#include <iostream>
using namespace std ;
class A 
{
    int a=0;
    public :
        void setval (int a)
        {
            a=a; // 10 = 10 
            this->a = a ; // 0 = 10 
        }
        void display()
        {
            
            cout<<"A = " << a ;     
        }
};
int main()
{
    std::cout<<"Hello World\n";
    A object ;
    object.setval(10);
    object.display();

    return 0;
}