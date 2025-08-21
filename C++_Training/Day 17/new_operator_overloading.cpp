#include <iostream>
using namespace std ;
class A 
{
    public :
    	int public_variable ; 
        virtual void draw()
        {
            cout<<"\nHi";
        }
        
        void * operator new (size_t size ) // here  this need to be as a member function of class A else it will be called by any new stmt 
		{
			cout<<"We are in new keyword overloading...\n";
			return new char[sizeof(A)] ; //A() ;	
		}
		
        ~A()
        {
        	cout<<"@ A Destructor \n";
		}
};


int main()
{
    cout<<"Hello World......\n";
    
    A * ptr = new A() ;
    
    cout<< "The address the ptr holds   : " << ptr << " \n "; 
    
    delete ptr ;
    
    return 0;
}
