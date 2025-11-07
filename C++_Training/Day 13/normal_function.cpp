#include<iostream>
using namespace std ;

class A 
{
  public: 
    int count;
    void print_count()
    {
        cout<<"Count  : " << count <<"\n";
    }
    
};


int main()
{
    A object ;
//    cout<<"object.count       : " << object.count << "\n" ; // static variable cant be accessed by the object 

    cout<<"object.A::count       : " << object.A::count << "\n" ; // static variable cant be accessed by the object 
	
//	object.print_count();  //static func cant be accessed by the object 
    object.A::print_count(); // can be called by the class 
    // ++count; // can be acccessed even in main fucntion due to static 
    
}