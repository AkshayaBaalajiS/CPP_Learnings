#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() {
        cout << "Drawing a shape\n";
    }
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a circle\n";
    }
};

int main() {
    Shape* shapePtr = new Circle();
    shapePtr->draw();
    delete shapePtr; // Freeing dynamically allocated memory
    return 0;
}