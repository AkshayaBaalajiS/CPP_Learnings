#include<iostream>
using namespace std ;

class A 
{
    public :
        float count=0;
    ~A()
    {
        cout<<"The value of the count " << count ;
    }
    // //THis willl allow only the void to int addition not other than that 
    // void operator + (int operand )
    // {
    //     this->count += operand ;
    // }
    // //This will work om void to double 
    // void operator + (double operand )
    // {
    //     this->count += operand ;
    // }
    //To make it work on all datatypes 
    A & operator + (int operand)
    {
        this->count += operand ;
        return *this;  // in obj + 5.234  it will return a object and when adding it with 5.232 the object returned is added with this 
        //cascading occured 

    }
    

};

int main()
{
    A object ;
    object + 5;
    object + 5.234;
    object + 5.234 + 5.232;

}