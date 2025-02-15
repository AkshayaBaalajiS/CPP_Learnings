#include <iostream>
using namespace std;

void fun(int a) {
    cout << a<<endl;
}

int main() {
    void (*ptr)(int) = fun;
    ptr(5);
}
