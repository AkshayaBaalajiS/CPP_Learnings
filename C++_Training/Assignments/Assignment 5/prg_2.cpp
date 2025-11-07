#include<iostream>
using namespace std;
class Publisher {
		char pub[12];
		double turnover;
	protected:
//		void register();
	public:
		Publisher(){ cout<<"@ Publisher constructor \n" ;};;
		void enter();
		void display();
		void size_find()
		{
			cout<<"\nsizeof(pub[12])" << sizeof(pub) <<"\n";
			cout<<"\nsizeof(turnover)" << sizeof(turnover) <<"\n";
		}
};
class Branch {
		char city[20];
	protected:
		float employees;
	public:
		Branch() { cout<<"@ Branch constructor \n" ;};
		void haveit();
		void giveit();
};
class Author : private Branch, public Publisher {
		int acode;
		
		char aname[20];
		float amount;
	public:
		Author() { cout<<"@ Author constructor \n" ;}
		void start();
		void show();
		void display_size()
		{
			cout<<"\nsizeof(acode)" << sizeof(acode) <<"\n";
			cout<<"\nsizeof(aname)" << sizeof(aname) <<"\n";
			
			cout<<"\nsizeof(amount)" << sizeof(amount) <<"\n";
			size_find();
		}
};
int main()
{
	Author object ;
//	object.haveit(); cant be done by us but can call the constructor by the compiler 
	cout<<sizeof(object);
	object.display_size();
}
//i. Write the names of data members, which are accessible from objects belonging to class Author.
// Data member accessed are NULL 

//ii. Write the names of all the member functions which are accessible from objects belonging to class Branch.
// Branch obj can access haveit() , giveit() , Branch () 

//iii. Write the names of all the members which are accessible from member functions of class Author.
// Publisher() , Branch()

//iv. How many bytes will be required by an object belonging to class Author?
//