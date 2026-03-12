#include <iostream>
#include <vector>
using namespace std;

struct Structure
{
	int a;
	float b;
	char c;
	double d;
	string e;
};

// void function(vector<Structure> v) // the signature should not be like this cause unnecessary copy happen 
void function(vector<Structure> & v)
{
	// for(auto  a : v ) // this signature should not be there it is costly cause copy happens here 
	for(const auto & a : v )
	{
		cout<<"a.a = " << a.a <<endl;
		cout<<"a.b = " << a.b <<endl;
		cout<<"a.c = " << a.c <<endl;
		cout<<"a.d = " << a.d <<endl;
		cout<<"a.e = " << a.e <<endl;
	}
}

int main()
{
	cout<<"This is the program to understand how the temporary object reference to be used \n";
	vector<Structure> vectStr;
	vectStr.resize(10);

	for(int i=0;i<10;i++)
	{
		vectStr[i].a += 1;
		vectStr[i].b += 1;
		vectStr[i].c += 'b';
		vectStr[i].d += 1;
		vectStr[i].e += "a";
	}
	function(vectStr);
}