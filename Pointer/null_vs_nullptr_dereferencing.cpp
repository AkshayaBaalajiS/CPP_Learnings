#include <iostream>
using namespace std;

int main() {
    int *p = NULL;
    // cout << *p;  // core dumped 

    int * ptr_1 = nullptr;
    cout << *ptr_1;  //  core dumped 
 
}
