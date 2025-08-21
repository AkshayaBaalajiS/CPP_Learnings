#include <iostream>
#include<cstring>
using namespace std;

//headerfile.h
class Mystring{
    private:
        char * m_p;
    public:
        Mystring();
        Mystring(const char *ptr);
        Mystring(Mystring & rhs);
        ~Mystring(); 
};

// definations or headerfile
Mystring::Mystring() { cout<<"Mystring:: empty string has been initiated. this ="<<this<<"\n";}
Mystring::~Mystring() { 
    cout<<"~Mystring:: empty string has been initiated. this ="<<this<<"\n";

    if(m_p){
        cout<<"initiated Mystring is setting to free...m_p"<<m_p<<"\n";
        delete [] m_p;
        cout<<" +- +- +- +- +- \n";
    }
}


Mystring::Mystring(const char *ptr){
    cout<<"Mystring(const char *ptr:string object initiated. this="<<this<<"\n";
    m_p = new char(strlen(ptr) +1);
    strcpy(m_p, ptr); // copy the string to that address 
}
// application-side
int main()
{
    cout<<"-------------\n";
    Mystring str1; //default construcor

    cout<<"-------------\n";
    Mystring str2("hello"); // single-parametarized construcor
    
    cout<<"-------------\n";
    Mystring str3(str2); //copy-construcotr
}