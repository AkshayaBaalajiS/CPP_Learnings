#include <iostream>
using namespace std;

int main()
{
	auto lambda_1 = [&](auto x, auto y) 
	{
		return x+y;
	};

	cout<<"lambda_1(1,1) = " << lambda_1(1,1) <<endl;
	cout<<"lambda_1(Akshaya Baalaji ,Senthilraj) = " << lambda_1(std::string("Akshaya Baalaji "),std::string("Senthilraj")) <<endl;
	cout<<"lambda_1('a','b') = " << lambda_1('a','b') <<endl;
	cout<<"lambda_1(34.324f,234.234f) = " << lambda_1(34.324f,234.234f) <<endl;
	
}