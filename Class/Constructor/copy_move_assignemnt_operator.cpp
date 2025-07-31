#include <iostream>
using namespace std;

class A 
{
	int a ;
	int b ;
	public :
		int c ;
		string d;
		char * e;

		A() : a(1), b(2), c(12), d("Akshaya Baalaji Senthilraj"), e("akshaya baalaji") 
		{
			cout<<"Default Constructor\n";
		}
		A(A & ref) // copy constructor 
 		{
			cout<<"Copy Constructor\n";
 			this->c = ref.c;
 			this->d = ref.d;
 			this->e = ref.e;
		}
		A(A && ref) // move constructor 
		{
			cout<<"Move Constructor\n";
 			this->c = ref.c;
 			this->d = ref.d;
 			this->e = ref.e;
		}
};

int main()
{
	A * aPtr =  new A();
	cout<<"d = " <<aPtr->d<<endl;
	cout<<"e = " <<aPtr->e<<endl;
	cout<<"c = " <<aPtr->c<<endl;

	cout<<"=-=-==-=-=-=-=-=-=-=--\n";
	A * lPtr =  new A(*aPtr);
	cout<<"d = " <<lPtr->d<<endl;
	cout<<"e = " <<lPtr->e<<endl;
	cout<<"c = " <<lPtr->c<<endl;
	cout<<"=-=-==-=-=-=-=-=-=-=--\n";
	

	cout<<"=-=-==-=-=-=-=-=-=-=--\n";
	A * mPtr =  new A(std::move(*aPtr));
	cout<<"d = " <<mPtr->d<<endl;
	cout<<"e = " <<mPtr->e<<endl;
	cout<<"c = " <<mPtr->c<<endl;
	cout<<"=-=-==-=-=-=-=-=-=-=--\n";
	

	// A * bPtr (aPtr); // either copy / move constructor is not called here 
	A * bPtr = aPtr;  


	cout<<"d = " <<bPtr->d<<endl;
	cout<<"e = " <<bPtr->e<<endl;
	cout<<"c = " <<bPtr->c<<endl;

	A * cPtr = std::move(bPtr);
	cout<<"d = " <<cPtr->d<<endl;
	cout<<"e = " <<cPtr->e<<endl;
	cout<<"c = " <<cPtr->c<<endl;

	cout<<"++++++++++++++++++++++++++++\n";

	A aObj = *aPtr;  

	cout<<"d = " <<aObj.d<<endl;
	cout<<"e = " <<aObj.e<<endl;
	cout<<"c = " <<aObj.c<<endl;

	A  dObj = std::move(aObj);
	cout<<"d = " <<dObj.d<<endl;
	cout<<"e = " <<dObj.e<<endl;
	cout<<"c = " <<dObj.c<<endl;

	cout<<"++++++++++++++++++++++++++++\n";

	A eObj(*aPtr);  
	cout<<"d = " <<eObj.d<<endl;
	cout<<"e = " <<eObj.e<<endl;
	cout<<"c = " <<eObj.c<<endl;

	A fObj (std::move(aObj));
	cout<<"d = " <<fObj.d<<endl;
	cout<<"e = " <<fObj.e<<endl;
	cout<<"c = " <<fObj.c<<endl;

	cout<<"++++++++++++++++++++++++++++\n";
}