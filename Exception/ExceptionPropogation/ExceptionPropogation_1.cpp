#include <iostream>
using namespace std;

void func3() {
    cout << "func3 start\n";
    throw runtime_error("Error in func3");
    cout << "func3 end\n";  // never executes
}

void func2() {
    cout << "func2 start\n";
    try
    {
        func3();
    }
    catch(std::exception & e)
    {
        cout<<e.what() <<endl;
    }
    cout << "func2 end\n";  // never executes
}

void func1() {
    cout << "func1 start\n";
    func2();
    cout << "func1 end\n";  // never executes
}

int main() {
    try {
        func1();
    }
    catch (const exception& e) {
        cout << "Caught in main: " << e.what() << endl;
    }
}
