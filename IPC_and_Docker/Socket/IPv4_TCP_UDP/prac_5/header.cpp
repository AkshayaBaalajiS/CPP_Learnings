#include "header.hpp"
using namespace std;

ostream & operator<<(ostream & out , DataStructure & ref)
{
	out<<ref.a << " --- " << ref.array << " --- " << ref.c << " --- " << ref.d << std::endl;
	return out;
}