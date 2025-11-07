#include <iostream>
using namespace std;

class classA
{
	public:
		int * data ;
		int size;
		classA( int size, int * dataa = nullptr ) :data(dataa), size(size)
		{
			cout<<"@classA constructor\n ";
		}

		classA(classA &ref )
		{
			size = ref.size;
			data=new int[ref.size];
			for(int i=0;i<ref.size;i++)
			{	
				data[i] = ref.data[i];
			}

			cout<<"@classA copy constructor\n ";
		}

		void functionToPrint(string a="")
		{

			cout<<a <<"@ function to print value \n";
			for(int i=0;i<size;i++)
			{
				cout<<data[i] << " ";
			}
			cout<<endl;
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
	
	classA object(5,array);
	cout<<"object class data member holds address =  " <<  object.data<<endl;

	classA object1 = object;
	cout<<"object 1 class data member holds address =  " <<  object1.data<<endl;

	*(object1.data) = 567;
	cout<<"object 1 class data member dereferencing value  =  " << *(object1.data)<<endl;
	cout<<"object class data member dereferencing value  =  " <<  *(object.data)<<endl;
	// after changing the value printing the values 
	object.functionToPrint("Original object ");
	object1.functionToPrint("Copied object ");

}