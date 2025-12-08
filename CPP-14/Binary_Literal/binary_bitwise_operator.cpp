#include <iostream>
#include <string>
using namespace std;

string DecToBin(int number)
{
	string value="";
	while(number!=0)
	{
		int mod = number % 2 ;
		value =  to_string(mod) + value;
		number = number/ 2;
	}
	return value;
}

int main()
{
	int binaryliteral1 = 0b01001 ;
	int binaryliteral2 = 0b10111 ;
	cout<< " binaryliteral1 = " << DecToBin(binaryliteral1) <<endl;
	cout<< " binaryliteral2 = " << DecToBin(binaryliteral2) <<endl;

	// & AND operator 
	cout<< " binaryliteral1 & binaryliteral2 = " << DecToBin(binaryliteral1 & binaryliteral2) <<endl;
	cout<< " binaryliteral1 | binaryliteral2 = " << DecToBin(binaryliteral1 | binaryliteral2) <<endl;
	cout<< " binaryliteral1 ^ binaryliteral2 = " << DecToBin(binaryliteral1 ^ binaryliteral2) <<endl;
	cout<< " ~binaryliteral2 = " << DecToBin(~binaryliteral2) <<endl;
	cout<< "binaryliteral1 << 1 " << DecToBin(binaryliteral1<<1) <<endl;
	cout<< "binaryliteral1>> 1 " << DecToBin(binaryliteral1>>1) <<endl;
	 
}