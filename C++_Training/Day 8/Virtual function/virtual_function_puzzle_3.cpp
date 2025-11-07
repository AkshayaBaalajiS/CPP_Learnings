#include <iostream>
using namespace std;

class A {
public:
    virtual void show() {
    // void show() {
        cout << "A\n";
    }
};

class B : public A {
public:
    void show() {
        cout << "B\n";
    }
};

int main() {
    B b;
    A* ptr = &b;
    ptr->show();
    return 0;
}