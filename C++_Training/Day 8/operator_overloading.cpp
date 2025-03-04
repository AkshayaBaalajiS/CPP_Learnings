#include<iostream>
using namespace std ;

class A 
{   
    
    friend void operator + (int args , A & ref );
    int private_integer=0;
    public:
            // int private_integer=0;
        // Commenting the below to show operator overloading in diff way globally 
        // void  operator + (int args )
        // {
        //     private_integer = private_integer + args ;
        //     cout<<"The data member value is : " << private_integer <<"\n" ;
        // }
        void display_values()
        {
            cout<<"The data member value is : " << private_integer <<"\n" ;
        } 
        void  operator = (A & ref  )
        {
            this->private_integer = ref.private_integer;
        }
        //We are going to do ++obj mean increment the datamember obj++ mean decremernt the datamember 
        //operator overloading 
        void  operator ++()
        {
            private_integer = private_integer +1 ;
            cout<<"After the increment  : " << private_integer <<"\n";
        }
        //for diff we are creating the argument for overloading to be done 
        void  operator ++(int args)
        {
            private_integer = private_integer - 1 ;
            cout<<"After the increment  : " << private_integer <<"\n";
        }
};
//2 + operator
void  operator + (int args , A & ref  )
{
    ref.private_integer= + args ;
    cout<<"The data member value is : " << ref.private_integer <<"\n" ;
}

int main()
{
    A object ;
    A object_1 ;
    object + 2;
    object_1 + 6;

    A object_2;

    object_2 = object_1; // here the assignment operation done and the CPU cycles wil be 4 because of the one data member (prev )
    //now we are creating the assignment operator overloading fucntion where we are copying the values    
    object_2.display_values();
    object_1.display_values();

    ++object_2;
    object_2++; // this will take the default argument as (0)
    
}