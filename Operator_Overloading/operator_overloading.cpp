#include <iostream>
using namespace std ;

class baseClass
{
    
    public:
        int variable;
        baseClass()
        {
            cout<<"The baseClass constructor called ..\n ";
        }
        
        ~baseClass()
        {
            cout<<"The baseClass destructor called ..\n ";
        }
        int operator + (baseClass & ref )
        {
            return (this->variable + ref.variable);
        }
        // ostream operator overloaded 
        friend ostream& operator << (ostream& out , const baseClass & ref );
        
        // new operator for the class overloaded 
        void * operator new (size_t size)
        {
            cout<<"The new operator overloaded inside the class  \n";  
            void * ptrr = (void * )malloc(size);
            if(!ptrr)
            {
                throw bad_alloc();
            }
            return ptrr;
        } 
};

// new operator other than class is overloaded 
void * operator new (size_t size)
{
    cout<<"The overloaded operator for new keyword called which is outside the class  ..\n";
    void * ptr = (void *)malloc(size);
    if(!ptr)
    {
        throw bad_alloc();
    }
    return ptr;
}

// friend function of the baseClass where the ostream operator overloaded  
ostream& operator << (ostream& out , const baseClass & ref )
{
    out<<"This is the object of baseClass..\n";
    return out;
}


int main()
{
    cout<<"This is the program to understand the << operator overloaded \n";

    baseClass object ;
    object.variable=10;
    cout<<object;

    baseClass object_1;
    object_1.variable=20;

    int result = object + object_1;
    cout<<"RESULT is  : " << result <<"\n";

    cout<<"+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_\n";
    baseClass * ptr_2 = new baseClass; // this will also call the new operator outside the class 
    cout<<"+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_\n";
    int * ptr_3 = new int(10); // this is the default new operator for the primitive type called not the baseClass overloaded new operator 
    cout<<"+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_\n";
    baseClass * ptr_4 = new baseClass(); // this will also call the new operator outside the class 

}