#include <iostream>

using namespace std;
template <typename T> 
T variable = T(123.1223423);	
int main()
{
	cout<<"This is the cpp program to understand the variable template \n";
	
	// T variable = 234; 
	cout<<"varibale = " << variable<int><<endl;

	variable<int> = 42;
    variable<double> = 3.14159;
    variable<char> = 'A';

    cout << "variable<int> = " << variable<int> << endl;
    cout << "variable<double> = " << variable<double> << endl;
    cout << "variable<char> = " << variable<char> << endl;
}
