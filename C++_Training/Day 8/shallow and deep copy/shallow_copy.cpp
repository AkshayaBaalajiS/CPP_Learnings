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
};

// definations or headerfile
Base::Base() { cout<<"Base:: empty string has been initiated. this ="<<this<<"\n";}

Base::Base(const char *ptr){
    cout<<"Base(const char *ptr:string )object initiated. this="<<this<<"\n";
    private_dm_ptr = new char(strlen(ptr) +1);
    strcpy(private_dm_ptr, ptr); // copy the string to that address 
}

Base::Base(Base & ref )
{
    this->private_dm_ptr = ref.private_dm_ptr ;
}


Base::~Base() { 
    cout<<"~Base:: empty string has been initiated. this ="<<this<<"\n";

    if(private_dm_ptr){
        cout<<"initiated Base is setting to free...private_dm_ptr"<<private_dm_ptr<<"\n";
        delete [] private_dm_ptr;
        cout<<" +- +- +- +- +- +- +- +- +-  \n";
    }
}



// application-side
int main()
{
    cout<<"-------------\n";
    Base str1; //default construcor

    cout<<"-------------\n";
    Base str2("hello"); // single-parametarized construcor
    
    cout<<"-------------\n";
    Base str3(str2); //copy-construcotr
}
/*
this copy constructor 
The data member is accessible for all objects with same value 

*/