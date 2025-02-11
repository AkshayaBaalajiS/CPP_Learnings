#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int *p = &a;
    int **q = &p;

    **q = 20;  // What will be the value of 'a' after this line?
    cout << a<<endl;
}
