#include <iostream>
using namespace std ;
class A 
{
    public :
        void draw()
        {
            cout<<"\nHi";
        }
};
int main()
{
    cout<<"Hello World\n";
    
    
    A * object = new(nothrow) A() ;  // new with no through return whatever the malloc return 
    object->draw();
    
    return 0;
}
