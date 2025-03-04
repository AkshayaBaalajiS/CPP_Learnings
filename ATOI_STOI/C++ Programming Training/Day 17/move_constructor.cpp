#include <iostream>
using namespace std ;
class A 
{
    public :
    	int * ptr ;
		A() : ptr (nullptr)
		{
			cout<<"@ A Default Constructor .....\n";
		}
		A(int a ) 
		{
			ptr = &a ;
			cout<<"@ A Single Parameterized Constructor .....\n";
		}
        
        //deep copy 
//		A(A & a ) 
//		{
//			cout<<"@ Copy Constructor (Deep copy ) \n";
//			ptr = new int(a.ptr );			
//		}

		//shallow copy 
//		A(A & a ) 
//		{
//			cout<<"@ Copy Constructor (Shallow copy ) \n";
//			this->ptr = a.ptr;			
//		}
		
		//move constructor 
//		A(A & a ) 
//		{
//			cout<<"@ Copy Constructor (Move  ) \n";
//			this->ptr = a.ptr;
//			a.ptr = nullptr ;			
//		}
		// to avoid the move constructor use the argument as const  (const A & a )
		
		
		A(A && a ) 
		{
			cout<<"@ Copy Constructor (Move with double reference  ) \n";
			this->ptr = a.ptr;
			a.ptr = nullptr ;			
		}
		void draw()
        {
            cout<<"\nHi";
        }
        
        ~A()
		{
			cout<<"@ A Destructor  .....\n";
			cout<<"The pointer before deletion holds  " << ptr << "  Value is  " << *ptr <<"\n";
			delete ptr ;
			ptr = nullptr ;
			cout<<"The pointer after deletion holds  " << ptr << "  Value is  " << *ptr <<"\n";
			
		}
};
int main()
{
    cout<<"Hello World\n";
    cout<<".........................\n";
//	A object ;  // freeing the resource at destructor cant be done here because of default constructor do initializer list 
	cout<<".........................\n";
    A object_1(10); 
	cout<<".........................\n" ;
    A object_2( std::move(object_1)); 
    cout<<".........................\n";

    return 0;
}
