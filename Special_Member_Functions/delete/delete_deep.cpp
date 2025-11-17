#include <iostream>
using namespace std;

class MyClass
{
public:
    // 1. Default Constructor
    MyClass() = delete;

    // 2. Destructor
    ~MyClass() = delete;

    // 3. Copy Constructor
    MyClass(const MyClass&) = delete;

    // 4. Copy Assignment Operator
    MyClass& operator=(const MyClass&) = delete;

    // 5. Move Constructor
    MyClass(MyClass&&) = delete;

    // 6. Move Assignment Operator
    MyClass& operator=(MyClass&&) = delete;
};

class MyClass1
{
public:
    // 1. Default Constructor
    MyClass1() = default;

    int function(int q) = delete;

    // 2. Destructor
    ~MyClass1() = delete;

    // 3. Copy Constructor
    MyClass1(const MyClass1&) = delete;

    // 4. Copy Assignment Operator
    MyClass1& operator=(const MyClass1&) = delete;

    // 5. Move Constructor
    MyClass1(MyClass1&&) = delete;

    // 6. Move Assignment Operator
    MyClass1& operator=(MyClass1&&) = delete;
};

int main()
{
    // MyClass obj;            // ❌ ERROR: default constructor deleted
    // MyClass a = obj;        // ❌ ERROR: copy constructor deleted
    // obj = a;                // ❌ ERROR: copy assignment deleted
    // MyClass b = MyClass();  // ❌ ERROR: move constructor deleted

    cout << "Class has all special member functions deleted.\n";

    // MyClass1 obj; // this cant be done cause the destructor deleted 
   MyClass1 * ptr = new MyClass1(); // this is used cause I done want the des to be called 


    return 0;
}
