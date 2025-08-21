#include <iostream>

using namespace std;

template<typename T>
class UniquePtr
{
	public:
		T * Pointer;
		UniquePtr()
		{
			Pointer = new T();
			cout<<"Custom_Unique_Pointer Constructor\n";
		}
		
		UniquePtr(int a)
		{
			Pointer = new T(a);
			cout<<"Custom_Unique_Pointer Parameterized Constructor\n";
		}

		UniquePtr(int a, char * b, int c)
		{
			Pointer = new T(a,b,c);
			cout<<"Custom_Unique_Pointer Parameterized Constructor\n";
		}

		// for making it unique 
		UniquePtr(UniquePtr & ref ) = delete;

		void operator = (UniquePtr & ref ) = delete ;

		~UniquePtr()
		{
			delete Pointer;
		}
};


class A 
{
	public :
		int a ;
		char * b ;
		int c ;
		A(int a, char * b, int c ) : a(a), b(b), c(c)
		{

		}
		A( ) : a(0), b(""), c(0)
		{

		}
};

int main()
{
	UniquePtr<A> some_pointer(10,"Akshaya Baalaji S", 34);
	cout<<"A = " << some_pointer.Pointer->a;
	cout<<"B = " << some_pointer.Pointer->b;
	cout<<"C = " << some_pointer.Pointer->c;

	// the baove works fine 

	// below performing copy and sassignment of it 
	// UniquePtr<A> some_pointer_1(some_pointer); // error: use of deleted function ‘UniquePtr<T>::UniquePtr(UniquePtr<T>&) [with T = A]’

	UniquePtr<A> some_pointer_1; 

	// some_pointer_1 = some_pointer; //  error: use of deleted function ‘void UniquePtr<T>::operator=(UniquePtr<T>&) [with T = A]’

}
