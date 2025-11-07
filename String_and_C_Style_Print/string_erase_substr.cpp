#include <string>
#include<iostream>
using namespace std;
int main()
{
	std::string str;
 
	str = "This is my string in C++";
	str.erase(4);
	std::cout << str << std::endl;
    std::cout << str.size() << std::endl;
    
    std::cout << "str.substr(0,0)   : " <<  str.substr(0,0) << std::endl; // this is to check what it will give 
	std::cout << "str.substr(0,1)    : " << str.substr(0,1) << std::endl;     
    
	str = "This is my string in C++";
	str.erase(7, 13);
	std::cout << str << std::endl;

	return 0;
}
