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
    
    // 1. unique_ptr<SampleClass> uptr;// when we dererference it we will get error because it is null (not initialized) 
    unique_ptr<SampleClass> uptr = make_unique<SampleClass>(243,354);
    uptr->print_function();
    // unique_ptr<SampleClass> uptr_1 = uptr ; // this cant be done on the unque ptr 

}