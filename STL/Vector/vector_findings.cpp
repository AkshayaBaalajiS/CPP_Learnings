/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
// #include <iostream>
// #include <vector>
// using namespace std;
// int main()
// {
//     std::cout<<"Hello World";
//     vector<int>a = {1,2,3};
//     for (int i : a )
//     {
//         cout << i << "   ";
//     }
//     cout<<endl;
//     int aa =a[0];
//     cout<<aa ;
//     return 0;
// }

// #include <iostream>
// #include <vector>

// int main() {
//     // Initializing two vectors
//     std::vector<int> vec1 = {1, 2, 3, 4, 5};
//     std::vector<int> vec2 = {10, 20, 30};
    
//     // Position at which to insert vec2 into vec1
//     int pos = 2;

//     // Insert elements of vec2 at position 'pos' in vec1
//     vec1.insert(vec1.begin() + pos, vec2.begin(), vec2.end());
    
//     // Printing the updated vec1
//     for (int val : vec1) {
//         std::cout << val << " ";
//     }

//     return 0;
// }


#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Initializing two vectors
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = {10, 20, 30};
    
    // Position at which to insert vec2 into vec1
    int pos = 2;

    // Insert elements of vec2 at position 'pos' in vec1
    // vec1.insert(vec1.begin() + pos, vec2.begin(), vec2.end());
    
    int max_ele = *max_element(vec1.begin(),vec1.end());
    std::cout<<max_element <<endl;
    // Printing the updated vec1
    // for (int val : vec1) {
    //     std::cout << val << " ";
    // }

    return 0;
}

