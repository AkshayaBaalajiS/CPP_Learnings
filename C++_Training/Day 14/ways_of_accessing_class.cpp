#include <iostream>
using namespace std ;

class A 
{
    public :
        int  a=23;
        void function()
        {
            cout<<"Hi\n" ;   
        }
};
int main()
{
    A object ;
    cout<<object.A::a ;
    object.A::function() ;
    
    return 0;
}