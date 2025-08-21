#include<iostream>
using namespace std ;

class A 
{
	public :
		A()
		{
			cout<<"@ A Constructor \n";
		}
			
		void allocate_memory()
		{
			cout<<"Class A Memory Allocated ....\n";
		}
		
		void deallocate_memory()
		{
			cout<<"Class A Memory Deallocated ....\n";
		}
		
		~A()
		{
			cout<<"@ A Destructor  \n";
		}
	
};
class B 
{
	public :
		B()
		{
			cout<<"@ B Constructor \n";
		}
			
		void allocate_memory()
		{
			cout<<"Class B Memory Allocated ....\n";
		}
		
		void deallocate_memory()
		{
			cout<<"Class B Memory Deallocated ....\n";
		}
		
		~B()
		{
			cout<<"@ B Destructor  \n";
		}
	
};
class C 
{
	public :
		C()
		{
			cout<<"@ C Constructor \n";
		}
			
		void allocate_memory()
		{
			cout<<"Class C Memory Allocated ....\n";
		}
		
		void deallocate_memory()
		{
			cout<<"Class C Memory Deallocated ....\n";
		}
		
		~C()
		{
			cout<<"@ C Destructor  \n";
		}
	
};

//middleware for reusing of the codes 
template <typename Type1 >
void render_function(Type1 & ref )
{
	cout<<"-------------------------\n";
	ref.allocate_memory();
	cout<<"-------------------------\n";
	ref.deallocate_memory();
	cout<<"-------------------------\n"; 
}

int main()
{	
	/*  
	The below violates the DRY principle 
	A a_object;
	cout<<"-------------------------\n";
	a_object.allocate_memory();
	cout<<"-------------------------\n";
	a_object.deallocate_memory();
	cout<<"-------------------------\n";
	
	
	B b_object ;
	//the below code is repeated so do the fucntional prog 
	cout<<"-------------------------\n";
	b_object.allocate_memory();
	
	cout<<"-------------------------\n";
	b_object.deallocate_memory();
	cout<<"-------------------------\n"; 
	*/
	
	A aa_object; 
	render_function (aa_object);
	
	B bb_object;
	render_function (bb_object);
	
	C cc_object ;
	render_function(cc_object);
	
}
