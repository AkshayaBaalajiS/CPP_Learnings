#include <iostream>
#include <memory>
using namespace std;

class Sample 
{
    public :
        int a ;
        int b;
        int c;
        
        Sample() : a(1), b(2), c(3)
        {
            cout<<"Sample class constructor \n";
        }
        
        
        ~Sample()
        {
            cout<<"Sample class Destructor \n";
        }
};


int main()
{
    cout<<"This is the program to understand the weak_ptr in C++\n";
    
    cout<<"______________________________\n";
    Sample obj; // constructor and destructor get called but here dynamic memory allcoation not happen 
    cout<<"______________________________\n";

    cout<<"++++++++++++++++++++++++++++++\n";    
    Sample * ptr =  static_cast<Sample *>(malloc(1000)); // nothing get called here only memory allocated 
    cout<<"++++++++++++++++++++++++++++++\n";    
   
    cout<<"=============================\n";     
    Sample * ptr_1 = new Sample(); // constructor get called destructor will not be called 
    cout<<"=============================\n";    


    cout<<"------------------------------\n";    
    unique_ptr<Sample> ptr_2 = make_unique<Sample>();
    cout<<"------------------------------\n"; 
    
    
    cout<<"*************************\n";    
    shared_ptr<Sample> ptr_4 = make_shared<Sample>();
    cout<<"*************************\n"; 
    
    
    cout<<"+++++++++++++++++++++++++++++++\n";
    cout<<"Shared Ptr usage \n";
    shared_ptr<Sample> shared_ptr_1 = ptr_4; // this will not call the constructor 
    
    cout<<"Use count of share ptr  =  "<<ptr_4.use_count()<<"\n";
    cout<<"+++++++++++++++++++++++++++++++\n";
    
    cout<<"+++++++++++++++++++++++++++++++\n";
    cout<<"Unique Ptr usage \n";
    // unique_ptr<Sample> unique_ptr_1 = ptr_2; // this cant be done as it is a unique_ptr
    unique_ptr<Sample> unique_ptr_1 = std::move(ptr_2); // here the constructor wont be called 
    cout<<"+++++++++++++++++++++++++++++++\n";
    
    cout<<"------------------------------\n"; 
    cout<<"Weak Ptr Usage \n";
    weak_ptr<Sample> weak_ptr = shared_ptr_1; // when we are assigning the shared_ptr to weak_ptr the shared_ptr count will not increase 

    cout<<"Use count of share ptr  =  "<<ptr_4.use_count()<<"\n";
    
    if(!weak_ptr.expired())
    {
        cout<<"For accessing use the lock() " << (*weak_ptr.lock()).a << endl;
    }
    
    shared_ptr_1.reset();
    cout<<"After the deletion of shared pointer \n";
    
    cout<<"Use count of share ptr  =  "<<ptr_4.use_count()<<"\n";
    
    if(!weak_ptr.expired())
    {
        cout<<"For accessing use the lock() " << (*weak_ptr.lock()).b << endl;
    }
    else
    {
        cout<<"Shared pointed reseted \n";
    }
    
    
    
    cout<<"------------------------------\n"; 
    
    cout<<"******************************\n"; 
    std::weak_ptr<Sample> weak_ptr_3;
    
    {
        shared_ptr<Sample> shared_ptr_3 = make_shared<Sample>();
        weak_ptr_3 = shared_ptr_3;
    }

    if(!weak_ptr_3.expired())
    {
        cout<<"Data = " << weak_ptr_3.lock()->b<<endl;
    }
    else
    {
        cout<<"Shared Pointer deleted \n";
    }
    
    cout<<"******************************\n"; 


    // Sample * ptr = new Sample();
    
}