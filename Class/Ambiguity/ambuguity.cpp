#include<iostream>
using namespace std;

class A {
public:
    void show() { cout << "Class A" << endl; }
};

class B : public A {
public:
    void show() { cout << "Class B" << endl; }
};

class C : public A {
public:
    void show() { cout << "Class C" << endl; }
};

class D : public B, public C {
public:
    // No ambiguity resolution for 'show()' method
    // void show() { cout << "Class D" << endl; } // if this is commented the ambigity occurs compiler confused which show should be called from b or c 
};

int main() {
    D obj;
    obj.show();  // Which show() should be called? B's or C's? Ambiguity!

}
