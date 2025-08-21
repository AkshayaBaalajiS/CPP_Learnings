#include <iostream>
using namespace std;

void  functio(int i)
{
    cout<<i<<endl;
}

int main()
{
    void (*f) (int);
    f= functio;
    f(12);
}