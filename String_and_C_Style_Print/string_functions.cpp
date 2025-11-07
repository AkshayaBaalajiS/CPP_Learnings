#include <iostream>
#include <string>
#include <algorithm>  // for reverse function

using namespace std;

int main() {
    // Taking string input from user
    string userInput;
    cout << "Enter a string: ";
    getline(cin, userInput);  // getline allows spaces in input

    // Display the original string
    cout << "Original string: " << userInput << endl;

    // 1. Length of the string
    cout << "Length of the string: " << userInput.length() << endl;

    // 2. Appending another string
    string toAppend = " World!";
    userInput.append(toAppend);
    cout << "After appending: " << userInput << endl;

    // 3. Substring (from index 0 to 5)
    cout << "Substring (first 5 characters): " << userInput.substr(0, 5) << endl;

    // 4. Find a substring in the string
    size_t found = userInput.find("World");
    if (found != string::npos) {
        cout << "'World' found at position: " << found << endl;
    } else {
        cout << "'World' not found" << endl;
    }

    // 5. Insert a string at a specific position
    userInput.insert(5, " Amazing");
    cout << "After inserting ' Amazing': " << userInput << endl;

    // 6. Replace part of the string
    userInput.replace(0, 5, "Hey");
    cout << "After replacing first 5 characters with 'Hey': " << userInput << endl;

    // 7. Erase a part of the string
    userInput.erase(0, 4);  // Erase first 4 characters
    cout << "After erasing first 4 characters: " << userInput << endl;

    // 8. Reverse the string
    reverse(userInput.begin(), userInput.end());
    cout << "Reversed string: " << userInput << endl;

    return 0;
}
/*
length(): Returns the length of the string.
append(): Appends another string to the original.
substr(): Returns a substring from the original string.
find(): Searches for a substring and returns the position.
insert(): Inserts a string at a specified position.
replace(): Replaces a portion of the string with another string.
erase(): Removes characters from the string.
reverse(): Reverses the string using the algorithm library.

 */