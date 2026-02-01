#include <iostream>
using namespace std;

struct DataStructure
{
	int a;
	float b;
	char c;
	double d;
	public:	
		DataStructure(int a=234, float b =234.34543, char c ='2' , double d=687.56756) : a(a), b(b), c(c), d(d)
		{
			cout<<"@ DataStructure class cons\n";
		}
		~DataStructure()
		{
			cout<<"@ DataStructure class destructor \n";
		}

		void operator+= (const int & ref )
		{
			this->a+=ref;
			this->b+=ref;
			this->c+=ref;
			this->d+=ref;
		}

		friend ostream & operator<< (ostream & out, DataStructure & r)
		{
			out<<" --- "<< r.a << " --- " << r.b  << " --- " << r.c <<" ---- " << r.d << " --- \n";
			return out;
		} 

};	