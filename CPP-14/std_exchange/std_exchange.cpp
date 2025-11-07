#include <memory>
#include <iostream>
#include <utility>
#include <functional>
using namespace std;


struct A 
{
	int a ;
	char c;
	float b;
	double d ;
	string s;

	std::function<void()> lambda1;
	A()
	{
		lambda1 = [*this]()
		{
			cout<<"----------------\n";
			cout << "a = "	<< a << endl;
		    cout << "c = " << c << endl;
		    cout << "b = " << b << endl;
		    cout << "d = " << d << endl;
		    cout << "s = " << s << endl;
			cout<<"----------------\n";
		};
	}
	A(int aa, char ca, float ba, double da, string sa) : a(aa), c(ca), b(ba), d(da), s(sa)
	{
		lambda1 = [*this]()
		{
			cout<<"----------------\n";
			cout << "a = "	<< a << endl;
		    cout << "c = " << c << endl;
		    cout << "b = " << b << endl;
		    cout << "d = " << d << endl;
		    cout << "s = " << s << endl;
			cout<<"----------------\n";
		};
	}
	// std::function<void()> lambda1 = [this]()
	// {
	// 	cout << "a = "	 << a << endl;
	//     cout << "c = " << c << endl;
	//     cout << "b = " << b << endl;
	//     cout << "d = " << d << endl;
	//     cout << "s = " << s << endl;
	// };
};


struct B : public A
{
	int a ;
	char c;
	float b;
	double d ;
	string s;

	std::function<void()> lambda1;

	B(int aa, char ca, float ba, double da, string sa) :  a(aa), c(ca), b(ba), d(da), s(sa)
	// B(int aa, char ca, float ba, double da, string sa) : A(aa+234,ca+1,ba+234.234,da+567.45,sa), a(aa), c(ca), b(ba), d(da), s(sa)
	{
		lambda1 = [*this]()
		{
			cout<<"----------------\n";
			cout << "a = "	<< a << endl;
		    cout << "c = " << c << endl;
		    cout << "b = " << b << endl;
		    cout << "d = " << d << endl;
		    cout << "s = " << s << endl;
			cout<<"----------------\n";
		};
	}

	B(int aa, char ca, float ba, double da, string sa, int aaa) : A(aa+234,ca+1,ba+234.234,da+567.45,sa), a(aa), c(ca), b(ba), d(da), s(sa)
	// B(int aa, char ca, float ba, double da, string ssa) : A(aa+234,ca+1,ba+234.234,da+567.45,sa), a(aa), c(ca), b(ba), d(da), s(sa)
	{
		lambda1 = [*this]()
		{
			cout<<"----------------\n";
			cout << "a = "	<< a << endl;
		    cout << "c = " << c << endl;
		    cout << "b = " << b << endl;
		    cout << "d = " << d << endl;
		    cout << "s = " << s << endl;
			cout<<"----------------\n";
		};
	}
};

// struct C 
// {
	
// 	C() {
		
// 	}
// };
int main()
{
	cout<<"this is the program to understand the std::exchange in cpp \n";
	int ia =12;
	int ib =345;
	cout<<"++++++++++++++\n";
	cout<<"Before \n";
	cout<<ia <<endl;
	cout<<ib <<endl;

	ib = exchange(ia, ib); // here ia get ib value and ia value get returned that we are assigninh to ib 

	cout<<"After \n";
	cout<<ia <<endl;
	cout<<ib <<endl;
	cout<<"++++++++++++++\n";


	char ca ='a';
	char cb = 'b';
	cout<<"Before \n";

	cout<<ca <<endl;
	cout<<cb <<endl;
	cb = exchange(ca, cb); // here ia get ib value and ia value get returned that we are assigninh to ib 

	cout<<"After \n";
	cout<<ca <<endl;
	cout<<cb <<endl;
	cout<<"++++++++++++++\n";


	double da =12.234234;
	double db =123421.234234;
	cout<<"Before \n";
	
	cout<<da <<endl;
	cout<<db <<endl;
	db = exchange(da, db); // here ia get ib value and ia value get returned that we are assigninh to ib 

	cout<<"After \n";
	cout<<da <<endl;
	printf("%f\n", da);
	cout<<db <<endl;
	cout<<"++++++++++++++\n";

	float fa =345.6456;
	float fb =1234345.6456;
	cout<<"Before \n";
	
	cout<<fa <<endl;
	cout<<fb <<endl;
	fb = exchange(fa, fb); // here ia get ib value and ia value get returned that we are assigninh to ib 

	cout<<"After \n";
	cout<<fa <<endl;
	cout<<fb <<endl;
	cout<<"++++++++++++++\n";

	// Cross change 
	// float to double 
	cout<<"Before \n";

	cout<<da <<endl;
	cout<<db <<endl;
	cout<<fb <<endl;

	db = exchange(da, fb); // float to double 
	// fb -> da
	// da -> db 
	cout<<"After \n";
	
	cout<<da <<endl;
	cout<<db <<endl;
	cout<<fb <<endl;
	cout<<"++++++++++++++\n";
	cout<<"Before \n";
	cout<<ia <<endl;
	cout<<ca <<endl;
	cout<<cb <<endl;
	ca = exchange(ia, cb); // here ia get ib value and ia value get returned that we are assigninh to ib 
	// cb to ia
	// ia -> cb 
	cout<<"After \n";
	cout<<ia <<endl;
	cout<<ca <<endl;
	cout<<cb <<endl;
	cout<<"++++++++++++++\n";

	// trying with pointer 
	char * cPtra = "Akshaya Baalaji s";
	char * cPtrb = "Vijayalakshmi G";
	cout<<"Before\n";
	cout<<cPtra <<endl;
	cout<<cPtrb <<endl;

	cPtrb = exchange(cPtra, cPtrb);
	cout<<"After\n";
	cout<<cPtra <<endl;
	cout<<cPtrb <<endl;

	cout<<"++++++++++++++\n";
	// working fine 
	A * strPtr = new A(12,'a',34.3434f,345.34534, "Akshaya Baalaji S");
	A * strPtr1 = new A(34,'b',678.6767f,67.6767, "Vijayalakshmi G");
	cout<<"Before\n";
	strPtr->lambda1();
	strPtr1->lambda1();

	strPtr1 = exchange(strPtr, strPtr1);
	cout<<"After\n";
	strPtr->lambda1();
	strPtr1->lambda1();

	cout<<"++++++++++++++\n";
	// working fine 
	B * strPtr3 = new B(67,'y',3454.3434f,2345.34534, "Baalaji S");
	B * strPtr4 = new B(56,'p',789.6767f,8978.6767, "Viji G");
	cout<<"Before\n";
	strPtr3->lambda1();
	strPtr4->lambda1();

	strPtr4 = exchange(strPtr3, strPtr4);
	cout<<"After\n";
	strPtr3->lambda1();
	strPtr4->lambda1();

	cout<<"++++++++++++++\n";
	// working fine 
	A * strPtr5 = new B(678,'yt',1212.3434f,124.34534, "Baalaji ");
	A * strPtr6 = new B(899,'pq',6784.6767f,2344.6767, "Viji ");
	cout<<"Before\n";
	strPtr5->lambda1();
	strPtr6->lambda1();

	strPtr6 = exchange(strPtr5, strPtr6);
	cout<<"After\n";
	strPtr5->lambda1();
	strPtr6->lambda1();

	A * strPtr7 = new B(75,'ju',34.3434f,453.34534, "Viji ");
	strPtr7->lambda1();

	A * strPtr8 = new B(67,'nh',8989.3434f,234.34534, "AB ", 1);
	strPtr8->lambda1();


	// will not work 

	unique_ptr<A> uniPtr11= make_unique<A>(899,'pq',6784.6767f,2344.6767, "Viji ");
	unique_ptr<A> uniPtr12= make_unique<A>(899,'pq',6784.6767f,2344.6767, "Viji ");

	// uniPtr12 = exchange(uniPtr11, uniPtr12);//  use of deleted function
}