#include <iostream>
#include <memory>

using namespace std;


class SampleClass
{
    public:
        int a;
        int b;
        SampleClass()
        {
            cout<<"@ SampleClass constructor \n";
        }
        SampleClass(int a, int b)
        {
            cout<<"@ SampleClass constructor \n";
            this->a=a;
            this->b=b;
        }
        void print_function()
        {
            cout<<" A = " <<a << "  B = " << b<<endl;
        }
        
        ~SampleClass()
        {
            cout<<"@ ~SampleClass Destructor\n";
        }
};
int main()
{
    cout<<"This is the program to understand the unique_ptr and shared_ptr in c++\n";
    
    shared_ptr<SampleClass> uptr = make_shared<SampleClass>(243,354);
    uptr->print_function();
    shared_ptr<SampleClass> uptr_1 = uptr ; // this can be done on the shared ptr 
    uptr_1->print_function();


    cout<<"Try value change of the data member of the copied ptr  \n";
    uptr_1->a = 123;
    uptr_1->b = 23;

    // let us check the shallow copy is done or deep copy is done 
    uptr_1->print_function(); // deep copy is done no value change on the prev prev when we change the value here 
    
    // here no call for the destructor of copied ptr because there is no unique copy fo the pointer because of the shared ptr 


}