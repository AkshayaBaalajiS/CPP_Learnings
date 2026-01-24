#include "header.hpp"
using namespace std;

void Structure::print(){
	cout<<"A = " << a;
	cout<<"B = " << b;
	cout<<"C = " << c;
	cout<<"D = " << d;
}

// the opeartor << is not a member of Structure soo Structure:: should not be there 
ostream & operator<<(ostream & out, Structure & ref)
{
	out<<ref.a << "  " << ref.b << "  " << ref.c <<"  " << ref.d << endl;
}