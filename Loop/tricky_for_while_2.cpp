#include <iostream>
using namespace std;

int main() {
    int i = 0;
    
    for (; i < 5; i++) {
        cout << i << " "; // 0 1 2 4 
        while (i == 2) { 
            i++;
            break;
        }
    }
    
    cout << endl << "Final value of i: " << i;
}
