#include <iostream>
using namespace std;

class Sample
{
	int * ptr ;
	public :
		class InnerSample
		{
			int a;
			float b;
			char c;
			public:
				InnerSample() : a(12), b(23.2323f), c('3')
				{
					cout<<"@ InnerSample constructor \n";
				}
				~InnerSample()
				{
					cout<<"@ InnerSample destructor \n";
				}
				friend ostream & operator<<(ostream & out, InnerSample & a)
				{
					out<<"Values  --- -- " << a.a << " -- " << a.b << " -- "<< a.c <<std::endl;
					return out;
				}
		};
	private:
	// class InnerSample; // this cause class redeclared withiin diff access 
		InnerSample * innerClass;
	
	public :
		Sample()
		{
			ptr= new int [30];
			innerClass = new InnerSample();
			cout<<"Sample class constructor\n\n";
		}
		InnerSample * getAddress()
		{
			return innerClass;
		}
		

		Sample(Sample & a) = delete;
		void operator=(Sample& a ) = delete;
		

		~Sample()
		{
			cout<<"Sample class destructor\n";
			delete [] ptr;
			delete innerClass;
		}
};

int main()
{
	cout<<"This is the program to understand the RAII on the dynamic memory allocation \n";
	Sample obj;
	cout<<"Address  = " << obj.getAddress()<<endl;
	Sample::InnerSample * ptr = obj.getAddress();
	cout<<*(ptr);

	// Sample obj1 = obj; // use of deleted function 
	Sample Obj1 ;
	Sample Obj2 ;
	// Obj1 = Obj2; // use of deleted function 
	


}