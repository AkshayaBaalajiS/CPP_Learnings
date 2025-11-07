/*#include<iostream>
using namespace std ;
class A
{
	public :
		A() 
		{
			cout<<"@A Constructor   " <<"\n";	
		}	
		~A() 
		{
			cout<<"@A Destructor   " <<"\n";	
		}	
		
};


int main()
{	
	A* obj = new A ();   // here the constructor will only be called 
	//A * ptr  = object is the above stmt and it will only call the constructor and wont call the destructor 
	cout<<"----------------\n";
//	delete obj; // here the destructor will be called 
//	if the delete is not there the obj is still alive and cant be reached and memory leak happen 
	
}
*/
//to solve the problem :
#include<iostream>
using namespace std ;
class A
{
	public :
		A() 
		{
			cout<<"@A Constructor   " <<"\n";	
		}	
		void display() const{
            cout << "A::display_function: " << endl;
        }
		~A() 
		{
			cout<<"@A Destructor   " <<"\n";	
		}	
		
};
class B
{
	public :
		B() 
		{
			cout<<"@B Constructor   " <<"\n";	
		}	
		void display() const{ 
            cout << "B::display_function : " << endl;
        }
		~B() 
		{
			cout<<"@B Destructor   " <<"\n";	
		}	
		
};
template <typename Type1>
class smart_pointer
{
	public :
		Type1 *ptr ;	
		smart_pointer(Type1 * p = nullptr) : ptr(p)
		{
			
		}
		smart_pointer()
		{
			cout<<"@ smart_pointer constructor \n";
		}
		
		Type1 * operator -> ()
        {
            return ptr;
        }
        
		~smart_pointer()
		{
			cout<<"@ smart_pointer destructor \n";
			delete ptr ; // this will call the destructor of the class A
		}
	
};


int main()
{	
	smart_pointer<A> a_ptr = new A(); // smart_pointer *p holds the new A()  in the copy constructor 
	//now we are going to call the member functions of A by operator overloading 
	
	
	smart_pointer<B> b_ptr = new B(); // smart_pointer *p holds the new A()  in the copy constructor 
	//now we are going to call the member functions of A by operator overloading 
	
	cout<<"--------------------------\n";
	a_ptr->display();
	cout<<"--------------------------\n";
	b_ptr->display();
	cout<<"--------------------------\n";
	
}


