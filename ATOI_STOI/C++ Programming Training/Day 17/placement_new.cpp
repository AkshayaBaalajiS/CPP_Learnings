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
        ~A()
        {
        	cout<<"@ A Destructor \n";
		}
};
class B : public A  
{
    public :
        void draw()
        {
            cout<<"\nHi";
        }
};

int main()
{
    cout<<"Hello World\n";
    char buffer[1024] ; // this is a created buffer to explicitly specify the size of the heap space 
    
	char *buffer_1= new char[10000]  ; // this is a created buffer to explicitly specify the size of the heap space 
    
    A * object = new(buffer) A() ;  
//  placement new will get memory in a huge size if 
//	we need memory the mem allocated will be of huge size 
    object->draw();
    
   
    A * ptr = new (buffer) A() ;
    A * ptr_1 = new (buffer + sizeof(A) ) A() ;
    A * ptr_2 = new (buffer + sizeof(A) * 2) A() ;
    A * ptr_3 = new (buffer + sizeof(A) * 3) A() ;
    A * ptr_4 = new (buffer+ sizeof(A) * 4) A() ;
    
    cout<< "The address the ptr holds   : " << ptr << " \n "; 
    cout<< "The address the ptr_1 holds   : " << ptr_1 << " \n "; 
    cout<< "The address the ptr_2 holds   : " << ptr_2 << " \n "; 
    cout<< "The address the ptr_3 holds   : " << ptr_3 << " \n "; 
    cout<< "The address the ptr_4 holds   : " << ptr_4 << " \n "; 
    
// in the below we have to change the size because it will points to same mem location and evereything will be overwritten 
//    A * ptr = new (buffer_1) A() ;
//    A * ptr_1 = new (buffer_1) A() ;
//    A * ptr_2 = new (buffer_1) A() ;
//    A * ptr_3 = new (buffer_1) A() ;
//    A * ptr_4 = new (buffer_1) A() ;
//    
//    cout<< "The address the ptr holds   : " << ptr << " \n "; 
//    cout<< "The address the ptr_1 holds   : " << ptr_1 << " \n "; 
//    cout<< "The address the ptr_2 holds   : " << ptr_2 << " \n "; 
//    cout<< "The address the ptr_3 holds   : " << ptr_3 << " \n "; 
//    cout<< "The address the ptr_4 holds   : " << ptr_4 << " \n "; 
//    delete ptr ;  // when using the placement with new operator the delete cant be done so we have to explicitly call the comstructor 
    ptr->~A();
    ptr_1->~A();
    ptr_2->~A();
    ptr_3->~A();
    ptr_4->~A();
    
    return 0;
}
