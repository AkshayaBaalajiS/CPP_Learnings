#include "header.hpp"
using namespace std;

void Structure::print()
{
	cout<<"Structure class print function \n";
}

ostream & operator << (ostream & out, Structure & ref )
{
	out<<"---" << ref.a << "---" << ref.b << "---"<<ref.c <<"---\n";
	return out;
}
