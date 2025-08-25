#include <iostream>
#include <tuple>

using namespace std;

void variadic()
{

}

template <typename T, typename... Type>
void variadic(T arg1, Type... arg2)
{
	cout<<"Type = " << typeid(arg1).name() <<"  Arg  = " << arg1<<endl;
	variadic(arg2...);
	cout<<"Trying indexing and pointer \n";
	//pack does not exist as a single container in memory
	// so below cant be done 
	// cout<<"*arg2 " << *arg2 <<endl;
	// cout<<"arg2[0] " << arg2[0] <<endl;
}

void variadic_2()
{

}

template <typename T, typename... Type>
void variadic_2(T arg1, Type... arg2)
{
	// cout<<"Type = " << typeid(arg1).name() <<"  Arg  = " << arg1<<endl;
	// variadic(arg2...);
	// cout<<"Trying indexing and pointer \n";
	auto tuple_1 = std::make_tuple(arg2...);

	for(auto i : tuple_1)
	{
		cout<<" i  = " << i << endl;
	}
}


int main()
{
	cout<<"This is the code to prac varidiac template \n";

	variadic(12,12.34f,32.23423423,'a',"asd e rt ert ert0", 23423.f);
	variadic_2(12,12.34f,32.23423423,'a',"asd e rt ert ert0", 23423.f);

}