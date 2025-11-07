#include <iostream>
using namespace std;

template <typename T>
class A
{
	public :
		T var ;
		T * ptr;
		A(T val) : var(val)
		{
			cout<<"@ A class constructor \n";
		}
		A(T * val) : ptr(val)
		{
			cout<<"@ A class constructor \n";
		}
		

		~A()
		{
			cout<<"@ A class destructor \n";
		}
		
};


int main()
{
	int arr[] = {1,2,3,4,5,6,7};
	int a =23;

	float farr[] = {1.23f,2.34f,45.546f,4.f,.5f,6.34f,734.3443f};
	float fa =23.23f;
	
	A classObj(a);
	A classPtr(arr);

	A classObj1(fa);
	A classPtr1(farr);

	cout<<" int class type variable  = " << classObj.var ;
	// cout<<" int class type variable  = " << *(classObj.ptr) ; // while derefering seg fault occurs
	
	cout<<" int class type variable 1 = " << classObj1.var ;
	// cout<<" int class type variable 1 = " << *(classObj1.ptr) ;
	
	cout<<" int * class type variable  = " << classPtr.var ;
	// cout<<" int *  class type variable  = " << *(classPtr.ptr) ;

	cout<<" int * class type variable 1  = " << classPtr1.var ;
	// cout<<" int *  class type variable 1 = " << *(classPtr1.ptr) ;


/*
if we are using the CPP 14 to compile
error: missing template arguments before ‘classObj’

prefer to use 17 and above 
*/


}