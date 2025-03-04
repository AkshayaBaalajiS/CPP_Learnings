#include<iostream>
using namespace std ;
template <typename Template>

class Outer
{
    Template private_mem_0;
    public : 
        Outer(int args=-1) : private_mem_0(args)
        {
            cout<<"@ Outer Constructor " << this <<"\n";
        }
        void sizes()
        {
            cout<<"sizeof(Outer) "<<sizeof(Outer)<<"\n";
            cout<<"sizeof(Outer::Nested) "<<sizeof(Outer::Nested)<<"\n";
        }
        void print_val()
        {
            cout<<"The value of Outer private_mem_0  is  : " << private_mem_0;  // if we try to access the private_mem_1 it is not declared inthis scope error 
        }
        ~Outer()
        {
            cout<<"@ Outer Destructor  "<<this<<"\n";
        }
    // private : if it is private no object will be craeted 
        class Nested
        {
            Template private_mem_1;
            public : 
                Nested(int args=-1) : private_mem_1(args)
                {
                    cout<<"@ Nested Constructor " << this <<"\n";
                }
                void print_val()
                {
                    cout<<"The value of Nested private_mem_1  is  : " << private_mem_1; 
                }
                ~Nested()
                {
                    cout<<"@ Nested Destructor  "<<this<<"\n";
                }
        };
};


void size()
{
    cout<<"The size of the Outer is : " << sizeof(Outer<int>)<<"\n"; 
    cout<<"The size of the Nested is : " << sizeof(Outer<double>::Nested)<<"\n";   
    cout<<"" ;
}
 
int main ()
{
    
    Outer<int>::Nested object_1;  // if the nested class is private the object cant be created 
    // size();
    cout<<"\n-------------------------------------------\n"; 
    // object_1.print_val();
    cout<<"-------------------------------------------\n";
    Outer<int> object;  // <int> here we are specifying the type needs to be integer
    cout<<"-------------------------------------------\n";
    // object.print_val();
    cout<<"\n-------------------------------------------\n";


}