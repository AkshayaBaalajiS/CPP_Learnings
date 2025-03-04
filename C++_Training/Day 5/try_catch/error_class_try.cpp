#include <stdio.h>
#include <iostream>
using namespace std;
 
//handle--file
void fun1() ;
 
class Error{
    public:
        int m_errno;
        Error(int arg=0)
        {
            this->m_errno = arg;
        }
        void handle()
        {
            cout<<"handling error::number"<<this->m_errno<<"\n";
        }
       
};
 
//application-side
int main()
{
    cout<<"app started\n";
    try{
        fun1();
    }
    // the below catch is ignored 
    // catch(int error_occur)
    // {
    //     cout<<"exception is hadnled here "<<error_occur<<"\n";
    // }
    // catch(Error errObj)
    // {
    //     cout<<"Exception is handled here\n";
    // }
    catch(...)
    {
        cout<<"All kind of exception are catched here \n";
    }
    cout<<"app ended\n";
}
 
void fun1()
{
    cout<<"gfun started\n";
    // this below 
    Error eObj(-1);
    throw eObj;
    // throw (-1); this throw make the first catch word 
    cout<<"gfun ended\n";
}
 
 