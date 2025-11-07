#include <iostream>
#include <memory>

using namespace std;

struct A 
{
	int a;
	int b;
	A(int a, int b) 
	{
		this->a =a;
		this->b= b;
	}
};

std::unique_ptr<A> make_unique()	
{
	std::cout<<"std::unique_ptr<A> make_unique1()\n";
	return make_unique<A>(12,12);
}

A * Pointer()
{
	return new A(1,3);
}

template<typename T, typename... TT>
// unique_ptr<T> make_unique1(TT... args ) // when we are using the below we can handle lvale and rvalue reference correctly 
unique_ptr<T> make_unique1(TT&&... args )
{
	std::cout<<"unique_ptr<T> make_unique(TT... args )\n";
	return make_unique<T>(args...);
}

// this creates the error cause it calls itself recursively so renaming the make_unique will work 
// template<typename T, typename... TT>
// unique_ptr<T> make_unique(TT... args ) 
// {
// 	std::cout<<"unique_ptr<T> make_unique(TT... args )\n";
// 	return make_unique<T>(args...); 
// }

int main()
{
	cout<<"This is the code to understand the make_unique in cpp\n";

	unique_ptr<A> uniPtr = make_unique1<A>(12,12);
	std::cout<<uniPtr->a <<std::endl;
	std::cout<<uniPtr->b <<std::endl;

	// unique_ptr<A> uniPtr1= make_unique();

	unique_ptr<A> uniPtr5 = make_unique<A>(12,12);
	std::cout<<uniPtr5->a <<std::endl;
	std::cout<<uniPtr5->b <<std::endl;


	A * ptr = new A(1,12);
	unique_ptr<A> uniPtr2(ptr);
	unique_ptr<A> uniPtr3(Pointer());
	unique_ptr<A> uniPtr4(new A(123,12));

}