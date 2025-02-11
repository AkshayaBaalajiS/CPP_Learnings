#include <iostream>
using namespace std;

int main() {
    int i = 0;
    for (i = 0; i < 5; i++) {
        cout << "Outer loop: " << i << " ";
        while (i == 3) {
            i++;
            cout << "Inner loop: " << i << " ";
        }
    }
    cout << "\nFinal value of i: " << i<<"\n";
}
