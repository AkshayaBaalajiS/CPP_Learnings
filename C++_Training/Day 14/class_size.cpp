#include <iostream>
using namespace std;
class Base {
    int a,b,c,d,e;
public:
 // virtual Base() {}   
};
void size()
{
    Base bobj;
    cout << sizeof(Base) << endl;
    cout << sizeof(bobj) << endl;
}
int main() {
    size();

   return 0;
}