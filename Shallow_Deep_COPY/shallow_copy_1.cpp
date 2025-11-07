#ifdef CPP
#include <iostream>
#endif

using namespace std;

int main()
{
    cout<<"This is the program to understand the deep copy in c++\n";

    int a=10;
    int * ptr = &a;
    int & ptr_1 = *ptr;
    ptr_1 = 123;
    
    cout<<"Here also shallow is applied \n";
    cout<<"a = " << a<<endl;
    cout<<"*ptr = " << *ptr<<endl;
    cout<<"ptr_1 = " <<ptr_1 << endl;
    

}