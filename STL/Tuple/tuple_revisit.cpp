#include <iostream>
#include <tuple>

using namespace std;

int main()
{
	cout<<"This is the program to understand the tuple C++ \n";

	int a =234;
	float b=234.2342f;
	char c='a';

	tuple<int, float, char> tuple_1 ;

	// make tuple ways  
	// 1 way 
	tuple_1 = make_tuple(a,b,c);
	tuple_1 = make_tuple<int, float, char> (234, 234.2342f, 'a');

	//get 
	cout<<"get<int>(tuple) == " << get<int>(tuple_1)<<endl;
	cout<<"get<float>(tuple) == " << get<float>(tuple_1)<<endl;

	//get with index 
	cout<<"get<0>(tuple) == " << get<0>(tuple_1)<<endl;
	cout<<"get<2>(tuple) == " << get<2>(tuple_1)<<endl;


	// tie 
	int aa;
	float bb;
	char cc;

	tie(aa,bb,cc) = tuple_1;
	cout<<"aa  =" <<aa <<endl;
	cout<<"bb  =" <<bb <<endl;
	cout<<"cc  =" <<cc <<endl;

	// structure binding 
	auto [aaa,bbb,ccc] = tuple_1;
	cout<<"aaa  =" <<aaa <<endl;
	cout<<"bbb  =" <<bbb <<endl;
	cout<<"ccc  =" <<ccc <<endl;

}