#include<iostream>
using namespace std ;
#define MAX 4

class A 
{
	int arr[MAX];
	int top ;
	public :
		A() : top(-1) { } 
		void push_back(int val )
		{
			arr[++top] = val;
		}
		int & operator[] (int index);
		// A & operator = (int val );	
		friend ostream & operator << (ostream & os  , A & rhs );
		// friend void operator = (int val ,  int vval );

		class Iterator
		{
			A * ptr ;
			int loc ;
			public :
				Iterator(A * p  , int loc) : ptr(p) , loc(loc)
				{

				}
				int operator != (Iterator rhs) {
					//here the object address and the index is checked 
					if(this->ptr ==  rhs.ptr)
					{
						if(this->loc == rhs.loc)
						{
							return 0;
						}
					} 
					return 1;
				}
				void operator ++ () {
					this->loc=this->loc +1 ;
				};
				int operator * () {
					return ptr->arr[loc]; 
				}

			
			
		};
		Iterator begin()
		{
			return Iterator(this,0);
		}
		Iterator end()
		{
			return Iterator(this,MAX);
		}
		 
};	
int & A::operator[](int index)
{
	cout<<"int &A::operator[](int index)    " << "and index =  " << index  << " \n";
	
	return this->arr[index] ;
}

ostream & operator << (ostream & os  , A & rhs )
{
	os << "ostream & operator << (ostream & os  , A & rhs )   : " << "\n";
	os << rhs.arr ;
	return os ;
}
int main()
{
	cout<<"Hi.............\n";
	A object;
	for (int i=0;i<MAX ;i++)
	{
		object.push_back(1000+i);	
	}	
	cout<<"-------------------\n";
	for (int i=0;i<MAX ;i++)
	{
		cout<< "object[" << i <<"]     :" ; 
		cout << object[i] ;
		cout<< " \n";	
	}	
	//iterator :
	// object.A::Iterator Iterator object = myarr.begin();  // why this error arraises 
	A::Iterator it = object.begin();
	for(int i=0; it!=object.end() ;++it , i++ )
	{
		cout<<"arr[" << i <<"]  : " << *it <<"\n"; 
	}
}
