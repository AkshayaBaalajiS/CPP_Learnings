#include<iostream>
#include<typeinfo> // Through this header we get the typeif object which helps in getting the type of the object 

using namespace std ;

//Here it occupies 1 byte we are wasting it to get the base address of it 
class new_class{};
struct new_struct{};


int main()
{
    cout << "The size of the class : " << sizeof(new_class)<<"\n";    
    cout << "The size of the Struct  : " << sizeof(new_struct)<<"\n";    
    

    cout<<"The type of the object created \n";
    //object creation 
    new_class c_object1 , c_object2 ;
    new_struct s_object1 , s_object2 ;

    cout << "Address of the class object is : " << &c_object1 << " The type of the class object  : " << typeid(c_object1).name()<<"\n";        
    cout << "Address of the class object is : " << &c_object2 << " The type of the class object  : " << typeid(c_object2).name()<<"\n";        
    cout << "Address of the struct object is : " << &s_object1 << " The type of the Struct object : " << typeid(s_object1).name()<<"\n";        
    cout << "Address of the struct object is : " << &s_object2 << " The type of the Struct object : " << typeid(s_object2).name()<<"\n";        


}