#include <iostream>
using namespace std;

int main() {
    int *p;
    {
        int a = 10;
        p = &a;
    }
    cout << *p;  // What will happen when dereferencing p?
}
