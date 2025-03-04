#include <iostream>
using namespace std;

namespace group1
{
    void gfun(const int * ptr) //receiving is as const ponitner
    {
        cout <<"Main : i = " << ptr << " , * ptr = " << *ptr << "\n";
        int *ip = NULL;
        ip = const_cast<int*> (ptr); //const_cast will convert the datatype in c++ 
        *ip = 1234; //when we want ot modify the const int pointer value, we should do this type
        cout << "ip = " << ip << ", *ip " << *ip << endl;
    }
    void main()
    {
        int i=10;
        cout << "Main : i = " << i << ", &i = " << &i << endl;
        gfun(&i);
    }
}

int main()
{
    group1::main();
}