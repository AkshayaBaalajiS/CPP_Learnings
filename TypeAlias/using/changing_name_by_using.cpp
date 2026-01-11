#include <iostream>
#include <vector>

using namespace std;

using INT = int;

using VEC_INT = vector<int>;


template<typename T>
using VECT = vector<T>;

int main()
{
	cout<<"@ changing the name by using in cpp\n";
	INT variable;

	VEC_INT vectorInt;
	vectorInt.resize(10);

	VECT<double> someVec;
	someVec.resize(12);	
}