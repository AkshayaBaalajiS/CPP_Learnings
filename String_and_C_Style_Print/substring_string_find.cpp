#include <iostream>
#include <string>

using std::string;

int main() {
  std::string mainString = "This is a sample string.";
//   std::string subString = "sample"; // it return 10 which is actually at 11
  std::string subString = "akshay";      // 

  size_t found = mainString.find(subString);
  // std::string::npos: This is a constant that represents the highest possible value for an index in a string. 
//   It is used to indicate that a substring was not found in the string.
  if (found != std::string::npos) {
    std::cout << "Substring found at position: " << found << std::endl;
  } else {
    std::cout << "Substring not found." << std::endl;
  }
  return 0;
}