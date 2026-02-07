#include <iostream>
#include <cstring>
#include <memory>
using namespace std;

class Sample
{
	public:
		char * ptr ;
		int a=234;

		Sample(int a=23):ptr(new char[50]), a(a)
		{
			cout<<"@ Sample class constructor \n";
		}

		~Sample()
		{
			cout<<"@ Sample class destructor \n";
			delete [] ptr;
		}		

};

int main()
{
	cout<<"Unique pointer on the Pointers \n";
	cout<<"-------Below is for Object -------\n";
		{	
			unique_ptr<Sample> up= make_unique<Sample>(12);
			// up->ptr = "Akshaya Baalaji S";
			strcpy(up->ptr, "Akshaya Baala.ji S ");
	
			cout<<"@ up->a " <<  up->a <<endl;
			cout<<"@ up->ptr " <<  up->ptr <<endl;
		}
		{
			unique_ptr<Sample> up(new Sample(34));
			// up->ptr = "Akshaya Baalaji S";
			strcpy(up->ptr, "Akshaya Baala.ji S ");
	
			cout<<"@ up->a " <<  up->a <<endl;
			cout<<"@ up->ptr " <<  up->ptr <<endl;
		}
	cout<<"-----------------------------------\n";
	// learning uniqueptr is itself a pointer so dereference it (*up) then [] index it for pointer 
	// learning uniqueptr is itself a pointer so dereference it (*up) then [][] double index it for double pointer  

	cout<<"-------Below is for Pointer -------\n";
	{
		// unique_ptr<Sample *> up= make_unique<Sample*>(new Sample[10](23)); // this cant be done on single line 
		unique_ptr<Sample *> up= make_unique<Sample*>(new Sample[10]);
			for(int i=0;i<10;i++)
			{
				strcpy((*up)[i].ptr, "Akshaya Baalaji S ");
		
				cout<<"@ (*up)[i].a " <<  (*up)[i].a <<endl;
				cout<<"@ (*up)[i].ptr " <<  (*up)[i].ptr <<endl;
			}
	}	

	cout<<"-------Below is for Double Pointer -------\n";
	{
		// unique_ptr<Sample *> up= make_unique<Sample*>(new Sample[10](23)); // this cant be done on single line 
		unique_ptr<Sample **> up= make_unique<Sample**>(new Sample*[5]);
			for(int i=0;i<5;i++)
			{
				(*up)[i]= new Sample[5];
				for(int j=0;j<5;j++)
				{
					strcpy((*up)[i][j].ptr, "Akshaya Baalaji S ");
				}
			}
			for(int i=0;i<5;i++)
			{
				for(int j=0;j<5;j++)
				{
					cout<<"@ (*up)[i][j].a " <<  (*up)[i][j].a <<endl;
					cout<<"@ (*up)[i][j].ptr " <<  (*up)[i][j].ptr <<endl;
				}
			}
	}	
	cout<<"-----------------------------------\n";
	
	Sample * samarr1 = new Sample[5]; //deffault cons get called here for 10 // if cons has args this cant be done 
	for(int i=0;i<5;i++)
	{
		samarr1[i] = *(new Sample(43));
	}
	// for(int i=0;i<10;i++)
	// {
	// 	samarr1[i] = *(new Sample(43));
	// }
	// compilation done but undefined behaviour 

	Sample ** samarr = new Sample*[5]; // cons get called here for 10 // if cons has args 
	for(int i=0;i<5;i++)
	{
		samarr[i] = new Sample(43);
	}
	// for(int i=0;i<10;i++)
	// {
	// 	samarr[i] = new Sample(43);
	// }
	// compilation done but undefined behaviou
}