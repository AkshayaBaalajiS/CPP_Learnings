#include<iostream>
using namespace std ;
/*class Shape {
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

void performDrawing(Shape& shape) {
	shape.draw();
}

int main() {
	Circle* circlePtr = new Circle();
	performDrawing(*circlePtr);
	return 0;
}

What will be the output of the above code?
		a.      Drawing a shape
		b.		Runtime error
		c.		Drawing a circle     <---
		d.		Compilation error
____________________________________________________
*/

/*
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

void performDrawing(Shape& shape) {

	shape.draw();

}

int main() {

	Circle* circlePtr = new Circle();

	performDrawing(*circlePtr);

	return 0;

}
What will be the output of the above code?
a.Drawing a shape
b.Runtime error
c.Drawing a circle    <----------
d.Compilation error

____________________________________________
*/
