#include <iostream>
using namespace std;

int main() {
    for (int i = 0; i < 5; ) {
        cout << i << " ";  // 0 1 2 
        if (i == 2) {
            i = 0;
            break;  // this breaks the outer loop 
        }
        i++;
    }
    cout << "\nEnd of program";
}
