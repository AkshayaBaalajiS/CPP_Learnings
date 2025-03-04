#include <iostream>
#include<cstring>
using namespace std;

//headerfile.h
class Base{
    private:
        char * private_dm_ptr;
    public:
        Base();
        Base(const char *ptr);
        Base(Base & rhs);
        ~Base(); 
        void display ()
        {
            cout <<"MyString is : " << private_dm_ptr <<"\n";
        }
};

// definations or headerfile
Base::Base() { cout<<" @ Constructor this ="<<this<<"\n";}  //Base:: empty string has been initiated.

Base::Base(const char *ptr){
    cout<<" @ Single Parameterized Constructor this="<<this<<"\n"; //Base(const char *ptr:string )object initiated.
    private_dm_ptr = new char(strlen(ptr) +1);
    strcpy(private_dm_ptr, ptr); // copy the string to that address 
}

Base::Base(Base & ref )
{
    cout<<" @ Copy Constructor this="<<this<<"\n";
    if(ref.private_dm_ptr)
    {
        this->private_dm_ptr =  new char[strlen(ref.private_dm_ptr) +1];
        strcpy(this->private_dm_ptr,ref.private_dm_ptr);
    }
    // move constructor 
    // below we are transferring the ownership 
    // this->private_dm_ptr = ref.private_dm_ptr;
    // ref.private_dm_ptr = NULL ;
    else{
        this->private_dm_ptr =  ref.private_dm_ptr ;   // here ref.private_dm_ptr which is holding the NULL 
    }
}


Base::~Base() { 
    cout<<" @ Destructor this ="<<this<<"\n"; //~Base:: empty string has been initiated.

    if(private_dm_ptr){
        cout<<"Freeing private_dm_ptr going on "<<private_dm_ptr<<"\n";
        delete [] private_dm_ptr;
        cout<<" +- +- +- +- +- \n";
    }
}

// application-side
int main()
{
    cout<<"-------------\n";
    // Base str1; //default construcor

    cout<<"-------------\n";
    Base str2("hello"); // single-parametarized construcor
    
    cout<<"-------------\n";
    Base str3(str2); //copy-construcotr

    str2.display();
    str3.display();
}
/*
this deep copy constuctor will make the seperate copy of the datamember  
this move constructor will transfer the ownership from the str2 to str3 
*/