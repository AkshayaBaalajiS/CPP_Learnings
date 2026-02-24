#include <iostream>
using namespace std;


volatile int a = 123; // volatile is form of req to compiler that the particular variable can be changed and dont optimize it  

int main()
{
	cout<<"This is the program to understand the volatile in cpp \n";
	cout<<"a  = " << a<<endl; 
}