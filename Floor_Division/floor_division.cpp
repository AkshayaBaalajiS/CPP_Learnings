/*
C++ does not have a // operator for floor division, like Python does. In C++, the // operator is used for single-line comments, not for division

3.4  -  > 3  
3.5  -  > 4 
*/

// #include <iostream>

// int main() {
//     int a = 7;
//     int b = 2;
//     int result = a / b; // performs floor division for positive numbers
//     std::cout << "Floor division result: " << result << std::endl;
//     return 0;
// }


#include <iostream>
#include <cmath> // for std::floor

int main() {
    double a = 7.5;
    double b = 2.0;
    double result = std::floor(a / b);
    std::cout << "Floor division result: " << result << std::endl;
    return 0;
}
