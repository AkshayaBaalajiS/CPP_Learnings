#include <iostream>
#include <memory>
#include <vector>
using namespace std;

template <typename T>
class A 
{
	public :
		T a;
		string strr;
		vector<T> vect;
		unique_ptr<T> uniqq;
};

int main()
{
	cout<<"This is the program to udnerstand the Herb Sutter Rule of 0 in modern CPP\n";
	A<string> aobj();
	A<int> aobj1();
}