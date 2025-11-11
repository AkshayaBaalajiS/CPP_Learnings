#include <iostream>
// #include <fixed> // no such include 
#include <iomanip>

using namespace std;

int main()
{
	cout<<"This is the program to understand the std fixed in cpp \n";

	float varf = 23.2323423446756; // this is the variable having more than 10 values after the point 

	std::cout << std::fixed << std::setprecision(5) ; // here we are setting the floating precision to be 5 
	std::cout<< varf << endl; // after setting the precision to 5 the variable will be having only 5 digits after the point 

	float fvar2 =  varf; // fixed does not affct the assignmentr stmt 
	std::cout << std::fixed << std::setprecision(9) ; // here we are setting the floating precision to be 9
	std::cout<< fvar2 << endl; // after setting the precision to 5 the variable will be having only 5 digits after the point 

	float fvar1 = 23.23;
	std::cout<< fvar1 << endl; // after setting the precision to 9 the variable with only 2 precision points is printing as 

	float fvar3 = 23.1f;
	std::cout<< fvar3 << endl; // after setting the precision to 9 the variable with only 2 precision points is printing as 


	// till the actual floating point the values are crt after that the value are not proper 


}