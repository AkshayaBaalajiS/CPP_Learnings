#include<iostream>
using namespace std ;

class A 
{   
    friend void operator + (int args , A & ref ); // this is for the 2+object 
    friend void  operator + (A & ref ,int args ) ; // this is for the object +2
    friend ostream & operator << (ostream & os , A & object );
    
    public:
        int private_integer;
            // int private_integer=0;
 
        A(int args = -1) : private_integer(args){}
        /*
        Commenting the below to show operator overloading in diff way globally 
        void operator + (int args )
        {
            private_integer = private_integer + args ;
            cout<<"The data member value is : " << private_integer <<"\n" ;
        }
        */
        void display_values()
        {
            cout<<"The data member value is : " << private_integer <<"\n" ;
        }
        void  operator = (A & ref  )
        {
            this->private_integer = ref.private_integer;
        }
        // //We are going to do ++obj mean increment the datamember obj++ mean decremernt the datamember
        // //operator overloading
        // void  operator ++()
        // {
        //     private_integer = private_integer +1 ;
        //     cout<<"After the increment  : " << private_integer <<"\n";
        // }
        // //for diff we are creating the argument for overloading to be done
        // void  operator ++(int args) // for diffrentiation we are putting the arguments 
        // {
        //     private_integer = private_integer - 1 ;
        //     cout<<"After the increment  : " << private_integer <<"\n";
        // }
        A & operator ++ ()
        {
            cout<<"A & operator ++ ()\n";
            ++this->private_integer;
            return *this ;
        }
        A & operator ++ (int val)
        {
            cout<<"A & operator ++ (int val ) : val \n";
            ++this->private_integer;
            return *this ;
        }
        /* Commenting to understand individually 

        // (object + 6 + 3 ) another function 
        A &  operator + (int args )
        {
            this->private_integer +=  args ;
            cout<<"The data member value is : " << this->private_integer <<"\n" ;
            return *this ;
        }
        */
       
       /*
        the below is for trying and wont work
    //    void  operator << (int a)
    //    {
    //         cout<<"This - " << this << "\n";
    //         return *this ; 
    //    }
        */
       
    /*
    // the below cant be done on class because it needs a object for accessing it 
    ostream & operator << (ostream & os , A & object )
    {
        os << "  the Variable value "<< object.private_integer<<  "\n";
        return os ; 
    }
    */
    
};


// ostream & operator << (ostream & os , A & object )
// {
//     os << "  the Variable value "<< object.private_integer<<  "\n";
//     return os ; 
// }

//(2 + object )  another global fucntion that act as the friend function in class and do a operator overloading
void  operator + (int args , A & ref  )
{
    ref.private_integer= + args ;
    cout<<"The data member value is : " << ref.private_integer <<"\n" ;
}

// (object + 6) another global fucntion that act as the friend function in class and do a operator overloading
void  operator + (A & ref ,int args )
{
    ref.private_integer= + args ;
    cout<<"The data member value is : " << ref.private_integer <<"\n" ;
}


int main()
{
    A object ;
    A object_1 (0) ;
    
    // 5+object ; void operator + (int args ) or void  operator + (A & ref ,int args )
    object_1 + 5  ; // void  operator + (int args , A & ref  )
    7+object_1; //void  operator + (A & ref ,int args )
    // object_1 + 8 + 4   ; // this will be done by the A& operator + (int args ) function
    
    cout<<"---------------------------\n";
    object_1.display_values();

    cout<<"---------------------------\n";

    A object_2;

    object_2 = object_1; //  void  operator = (A & ref  )
    /*
    here the assignment operation done and the CPU cycles wil be 4 because of the one data member (prev )
    now we are creating the assignment operator overloading fucntion where we are copying the values
    */

    // object_2.display_values();
    // object_1.display_values();

    ++object_2; //void  operator ++()  or  A & operator ++ ()
    object_2++; //void  operator ++(int args)   or   A &  operator + (int args )

    ++object_2++; //A & operator ++ (int val ) : val      and        A & operator ++ ()
    // the above will take the default argument as (0)


    cout << object_2; // this is not supported until the fucntion for the overloading is created  
}