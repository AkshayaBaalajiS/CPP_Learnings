#include <iostream>
#include <stdexcept>
using namespace std;
 
int main()
{
 
    // try block
    try {
        int numerator = 10;
        int denominator = 0;
        int res;
 
        // check if denominator is 0 then throw runtime
        // error.
        if (denominator == 0) {
            throw runtime_error("Division by zero not allowed!");
//            throw compiletime_error("Division by zero not allowed!"); there is no compiletime_error 
            
        }
 
        // calculate result if no exception occurs
        res = numerator / denominator;
        //[printing result after division
        cout << "Result after division: " << res << endl;
    }
    // catch block to catch the thrown exception
    catch (const exception& e) {
        // print the exception using the what function 
        cout << "Exception " << e.what() << endl;
    }
 
    return 0;
}
