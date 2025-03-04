#include<iostream>
using namespace std;

class Test
{
    public:
      //  static void fun() { }  
      // virtual void fun() { } - virtual function needs obj
      virtual static void fun() { }
};

int main()
{
    Test t1;
    t1.fun(); // Test::fun() in modern cpp std, we can directly access the static member function using objects
    Test::fun();
}