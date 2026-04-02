#include <iostream>
#include "header.hpp"
using namespace std;


int main(){
	cout<<"This is the program to work on dynamic and static library\n";
	// A obj;
	A * ptr = new B();	

	delete(ptr);
}