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

template <typename T, int N , typename ArrayT>
class Base
{
	public:
		int a;
		Base()
		{
			cout<<"@ Base class constructor \n";
		}

		~Base()
		{
			cout<<"@ Base class destructor \n";
		}
};


template <typename T, int N >
class A <T,N, false> : Base<T,N,T[N]> // T[N ] creates a T type array of N elements 
{
	public:
		int a;
		A()
		{
			cout<<"@ A <T,N, false> class constructor \n";
		}

		~A()
		{
			cout<<"@ A <T,N, false> class destructor \n";
		}
};

template <typename T, int N >
class A <T,N, true> : Base<T,N,T[N]> // T[N ] creates a T type array of N elements 
{
	public:
		int a;
		A()
		{
			cout<<"@ A <T,N, true> class constructor \n";
		}

		~A()
		{
			cout<<"@ A <T,N, true> class destructor \n";
		}
};

int main()
{

	A<int, 2, false> obj;

	A<int, 2, true> obj1;
}