#include <iostream>
using namespace std;

class Sample
{
	public :
		int a;
		int b ;
		int c ;

		Sample()
		{
			cout<<"@ Sample class constructor \n";
		}

		// operator << overloading 
		friend ostream & operator<< (ostream & out, Sample & arg)
		{
			out<<"Sample class object printed \n";
		}

		void operator+= (const int  args )
		{
			this->a+=args;
		}

		Sample operator+ (const int  args )
		{
			this->a+=args;
			return *this;
		}

		Sample operator+ (Sample args )
		{
			this->a+=args.a;
			this->b+=args.b;
			this->c+=args.c;
			return *this;
		}

		void operator= (Sample args )
		{
			if(this!=nullptr)
			{
				this->a = args.a;
				this->b = args.b;
				this->c = args.c;
			}
		}

		~Sample()
		{
			cout<<"@ Sample class destructor \n";
		}
	
};

int main()
{
	cout<<"@ Operator overloading \n";
	Sample obj;
	Sample obj1;
	// operator<< overloading 
	cout<< obj;

	// operator+= overloading 
	obj+=10;

	// operator+ overloading && operator= overloading 
	obj= (obj+10);

	// overloading overloaded operator+ and opeartor = overloaded 
	obj = obj+obj1;

}