#include <iostream>
#include <functional>
using namespace std;

int main(int argc, char **args )
{
	cout<<"Lambda functions \n";

	// int add_with_number = [] (int a){ // type conversion error ‘main()::<lambda(int)>’ to ‘int’
	// auto is prefered 

	// [] is the capture class () functional parameters like normal function 
	std::function<int(int)> add_with_number = [](int a) {
		return a + a;
	};
	int number  = stoi(args[1]);

	cout<<"Number  = " << number << "\nAfter adding the number with the same number : " <<add_with_number(number)<<endl; 
}