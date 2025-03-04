#include<iostream>
using namespace std;

class Base
{
public:
Base()
{
    cout << "Base cons\n";
}

~Base()
{
    cout << "~Base des\n";
}
    virtual void show() {
        cout << "virtual in base\n";
    };
};

class Derived: public Base
{
public:
    void show() { cout<<"In Derived \n"; }
    ~Derived()
{
    cout << "~Dericved des\n";
}

};

int main(void)
{
 //   Derived d;
    Base *br =new Derived();
    br->show();
    delete br;
    return 0;
}