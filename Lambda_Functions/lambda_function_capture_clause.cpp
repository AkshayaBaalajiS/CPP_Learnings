#include <iostream>
#include <functional>

using namespace std;

void function_to_print(int & x, int &y)
{
	cout<<"X = "<<x<<endl;
	cout<<"Y = "<<y<<endl;
}

int main()
{
	int x =3;
	int y =4;

	function_to_print(x, y);

	auto result = [&x, &y]()
	{
		x=x+1;
		y=y+1;
	};

	cout<<"________________________\n";
	result();
	function_to_print(x, y);
	cout<<"________________________\n";

	

}