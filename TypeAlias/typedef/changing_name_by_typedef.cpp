#include <iostream>
#include <vector>

using namespace std;

typedef int INT ;

typedef vector<int> VEC_INT ;

// error  template declaration of ‘typedef’
// template<typename T>
// typedef vector<T> VECT;

int main()
{
	cout<<"@ changing the name by typedef in cpp\n";
	INT variable;

	VEC_INT vectorInt;
	vectorInt.resize(10);
}