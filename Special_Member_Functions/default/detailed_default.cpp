#include <iostream>
using namespace std;

class MyClass
{
public:
    // 1. Default Constructor
    MyClass() = default;

    // 2. Destructor
    ~MyClass() = default;

    // 3. Copy Constructor
    MyClass(const MyClass&) = default;

    // 4. Copy Assignment Operator
    MyClass& operator=(const MyClass&) = default;

    // 5. Move Constructor
    MyClass(MyClass&&) = default;

    // 6. Move Assignment Operator
    MyClass& operator=(MyClass&&) = default;
};

int main()
{
    MyClass a;                // default constructor
    MyClass b = a;            // copy constructor
    MyClass c;                
    c = a;                    // copy assignment

    MyClass d = MyClass();    // move constructor
    MyClass e;
    e = MyClass();            // move assignment

    cout << "All defaulted special member functions executed!\n";
}

/*
MyClass a; → default constructor

MyClass b = a; → copy constructor

c = a; → copy assignment

MyClass d = MyClass(); → move constructor

e = MyClass(); → move assignment
*/