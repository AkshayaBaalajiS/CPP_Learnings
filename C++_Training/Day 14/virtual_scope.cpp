#include <iostream>
using namespace std;

class A
{
public:
    virtual void fun() { cout << "A"; }
};

class B: public A
{
public:
   void fun() { cout << "B"; }
};

class C
{
public:
   void fun() { cout << "C"; }
};
class D: public C
{
public:
   void fun() { cout <<"D"; }
};

int main()
{
    // B *bp = new D();
    // bp->fun();
    C * cp = new D;
    cp->fun();
    return 0;
}