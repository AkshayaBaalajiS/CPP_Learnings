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

class C : public B {
public:
    void show() override {
        cout << "C\n";
    }
};

int main() {
    A* arr[3] = { new A(), new B(), new C() };
    for (int i = 0; i < 3; ++i) {
        arr[i]->show();
    }

    // Freeing dynamically allocated memory
    for (int i = 0; i < 3; ++i) {
        delete arr[i];
    }

    return 0;
}