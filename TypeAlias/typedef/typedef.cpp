#include <iostream>
#include <vector>
using namespace std;

typedef int INT; 

// template <typename T>
// typedef std::vector<T> Vec; //  template declaration of ‘typedef’

int main()
{
	cout<<"This is the program to mdedmonstrate the typedef in cpp \n";
	INT a = 12;
	cout<<"A = " << a <<endl;
	cout<<"Type of A = " << typeid(a).name() <<endl;
}
