#include <iostream>
using namespace std;

class Sample
{
	public :
		Sample()
		{
			// cout<<"@ Sample class cons\n";
		}

		~Sample()
		{
			cout<<"@ Sample class des\n";
		}
};

class Sample1 : public Sample
{
	public :
		Sample1()
		{
			// cout<<"@ Sample1 class cons\n";
		}

		~Sample1()
		{
			cout<<"@ Sample1 class des\n";
		}
};


class Animal
{
	public :
		Animal()
		{
			// cout<<"@ Animal class cons\n";
		}

		virtual ~Animal()
		{
			cout<<"@ Animal class des\n";
		}
};

class ChildAnimal : public Animal
{
	public :
		ChildAnimal()
		{
			// cout<<"@ ChildAnimal class cons\n";
		}

		~ChildAnimal()
		{
			cout<<"@ ChildAnimal class des\n";
		}
};
int main()
{
	cout<<"virtual on destructr \n";

	Sample * ptr = new Sample();
	delete ptr;
	// the above will not call the sample class des 
	cout<<"--------------------------\n";
	Sample * ptr2 = new Sample1();
	delete ptr2;

	// the above will call only the des of base class 
	cout<<"--------------------------\n";

	Animal * ptr3 = new Animal();
	delete ptr3;
	// the above will not call the sample class des 
	cout<<"--------------------------\n";

	Animal * ptr4 = new ChildAnimal();
	delete ptr4;

	// the above will call only the des of base class 

	
}