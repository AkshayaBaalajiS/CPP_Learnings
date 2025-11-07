#include <iostream>
#include <vector>
using namespace std;

int function_1()
{
	return 10;
}

char function_2()
{
	return 'a';
}

vector<int> function_3()
{
	static vector<int> vec_t ;
	vec_t.resize(10);

	return vec_t;
}


int main()
{
	cout<<"Decltype in c++\n";
	int a =345;
	decltype (a) b =2345;
	cout<< " A = " << a << "  B = " << b  <<endl;

	decltype (function_1()) c; 
	decltype (function_2()) d;
	decltype (function_3()) e;


 	cout<<" Type C  = " << typeid(c).name() <<endl;
 	cout<<" Type D = " << typeid(d).name() <<endl;
 	cout<<" Type E = " << typeid(e).name() <<endl;
}