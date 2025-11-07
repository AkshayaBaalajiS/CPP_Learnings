#include <iostream>

using namespace std;

class A {
public:
    virtual void show() {
        cout << "A\n";
    }
};

class B : public A {
public:
    void show() override {
        cout << "B\n";
    }
};

void display(A obj) {
    obj.show();
}

int main() {
    B b;
    display(b);
    return 0;
}
