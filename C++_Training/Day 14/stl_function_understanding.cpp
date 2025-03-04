#include<iostream>
using namespace std ;
#define MAX 4

class A 
{
	int arr[MAX];
	int top ;
	public :
		A() : top(-1) { } 
	    int & operator[] (int index);
		void operator = (int val );	
		friend ostream & operator << (ostream & os  , A & rhs );
		// friend void operator = (int val ,  int vval );
};	
int & A::operator[](int index)
{
	cout<<"int &A::operator[](int index)    " << "and index =  " << index  << " \n";
	
	return this->top ;
}

void A::operator = (int val )
{
    this->top = val ;
}

ostream & operator << (ostream & os  , A & rhs )
{
	os << "ostream & operator << (ostream & os  , A & rhs )   : " << "\n";
	os << rhs.top ;
	return os ;
}
int main()
{
	cout<<"Hi.............\n";
	A object[MAX];
	for (int i=0;i<MAX ;i++)
	{
		object[i] = i*10 ;	
	}	
	cout<<"-------------------\n";
	for (int i=0;i<MAX ;i++)
	{
		cout<< "object[" << i <<"]     :" ; 
		cout << object[i] ;
		cout<< " \n";	
	}	
    
	cout<<"-------------------\n";
	
}

