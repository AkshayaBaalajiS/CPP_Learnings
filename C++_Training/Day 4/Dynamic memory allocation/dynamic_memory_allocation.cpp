#include<iostream>
#include<cstdlib>
using namespace std;

namespace group1
{
    class A
    {
        int private_variable;
        public :
            A(int private_variable=-1) // making the parameter as the default argument 
            {
                this->private_variable = private_variable ;
                cout<<"@ Constructor  "<<this <<"\n";
            } 
            ~A()
            {
                cout<<"At destructor the value is : " << private_variable <<"  The Address is " << this  << "\n";
            }
            int get_the_private_val()
            {
                return this->private_variable ;
            }
    };
    int a ;
    int *p = NULL ;
    void pointer_undersatnding_function()
    {
        cout <<"Address pointer = " << p << " \n";
    
        p = (int *) malloc (sizeof(int));  // tupe cast to (int *) because return type of malloc is void *

        if(p == NULL)
        {
            cout<<"THe space is not allocated \n";
        }
        cout<<"Address pointer = " << p <<"\n";
        *p = 1234 ;
        cout<<"Value of pointer = " << *p <<"\n";

        free(p); 
        p = NULL ; // to avoid the dangling pointer 

        cout <<"After free the Address pointer  = " << p << " \n";  //p is still dangling through memory is freed 
    }
    void class_access(int args)
    {
        A object(args);
        int result_value = object.get_the_private_val();
        cout<<"This is from the funciton of the namespace hold the provate var of class : " << result_value <<"\n"; 
        //the above will be printed first and the object ends so the destructor called 


        A() ; // this will automatically call the constructor and destuctor  
        //int(10) will call its own constructor / destructor Here it is not shown because it is a primitive type 
    }

    void pointer_on_class_type ()
    {
        A *ptr = NULL ;
        ptr = (A *) malloc (sizeof(A));
        if(ptr == NULL)
        {
            cout<<"Memory not assigned " <<"\n";
        }
        cout<< ptr <<"\n"; 
        cout<<"........................\n";
        ptr = new A(10);
        cout<<"The address of the ptr " << ptr <<"\n";

        int result = ptr->get_the_private_val();
        cout << "The private var from the class printed from the func  : " << result <<"\n";

        delete ptr ; // delete will automatically call the destructor 
    }
    
};



int main()
{
    // int n ;
    // cout<<"Enter a number  : " ;
    // cin >> n ;

    // group1::class_access(n);

    group1::pointer_on_class_type();

}