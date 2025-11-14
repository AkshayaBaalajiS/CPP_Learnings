#include <iostream>

using namespace std;

template <typename T, int N , bool Type>
class A 
{
	public:
		int a;
		A()
		{
			cout<<"@ A class constructor \n";
		}

		~A()
		{
			cout<<"@ A class destructor \n";
		}
};
template <>
class A <float,5, false>
{
	public:
		int a;
		A()
		{
			cout<<"@ A <float,5, false> class constructor \n";
		}

		~A()
		{
			cout<<"@ A <float,5, false> class destructor \n";
		}
};
template <>
class A <double,5, false>
{
	public:
		int a;
		A()
		{
			cout<<"@ A <double,5, false> class constructor \n";
		}

		~A()
		{
			cout<<"@ A <double,5, false> class destructor \n";
		}
};

int main()
{

	A<int, 2, false> obj;

	A <float,5, false> obj1;
	
	A <double,5, false> obj2;

}	