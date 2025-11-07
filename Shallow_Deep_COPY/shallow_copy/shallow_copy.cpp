#include <iostream>
using namespace std;

class classA
{
	public:
		int * data ;

		classA(int * dataa = nullptr) : data(dataa)
		{
			cout<<"@classA constructor\n ";
		}

		// there is no copy constructor so compiler creates it own and shallow copy occurs 
		// this is how the default copy constructyort looks like 
		classA(classA &  ref)
		{
			cout<<"@ classA copy constructor \n";
			data=ref.data;
		}

		~classA()
		{
			cout<<"@classA destructor\n ";
		}
		
};

int main()
{
	cout<<"This is the program to understand the usecase or working pf shallow copy \n";
	int array [] ={12,23,34,45,56};
	cout<<"The array address = " << array<<endl;
	
	classA object(array);
	cout<<"object class data member holds address =  " <<  object.data<<endl;

	classA object1 = object;
	cout<<"object 1 class data member holds address =  " <<  object1.data<<endl;

	*(object1.data) = 567;
	cout<<"object 1 class data member dereferencing value  =  " << *(object1.data)<<endl;
	cout<<"object class data member dereferencing value  =  " <<  *(object.data)<<endl;
}