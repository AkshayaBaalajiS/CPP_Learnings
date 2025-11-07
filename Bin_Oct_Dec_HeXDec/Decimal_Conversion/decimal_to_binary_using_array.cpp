#include <iostream>
using namespace std;

void decimalToBinary(int n) {
    if (n == 0) {
        cout << "Binary: 0" << endl;
        return;
    }

    // Array to store binary digits (maximum 32 bits for a standard int)
    int binary[32];  // Enough to store binary representation of any int
    int index = 0;   // Index for binary array

    // Continue dividing the number by 2 and storing remainders
    while (n > 0) {
        binary[index] = n % 2;   // Store remainder (0 or 1)
        n = n / 2;               // Update the number by dividing by 2
        index++;
    }

    // Print the binary digits in reverse order
    cout << "Binary: ";
    for (int i = index - 1; i >= 0; i--) {
        cout << binary[i];
    }
    cout << endl;
}

int main() {
    int decimal;
    cout << "Enter a decimal number: ";
    cin >> decimal;

    decimalToBinary(decimal);

    return 0;
}
