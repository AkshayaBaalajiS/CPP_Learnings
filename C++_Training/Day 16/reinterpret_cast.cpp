#include <iostream>
#include <functional>
using namespace std;


struct Derived; //forward Declaration
template <class T>
struct Base{
 
    void m_fun()
    {
        (reinterpret_cast<T *>(this)) -> m_vfun();
//	   m_vfun();    THIS WILL CALL THE BASE CLASS FUCNTION ONLY SO WE USE THE REINTERPRET CAST
//        func();

    }
    //virtual 
    void m_vfun()
    {
        cout<<"Base::m_vfun..\n";
    }
    void func()
    {
    	cout<<"Base :: function \n"; 
	}
};

struct Derived : Base<Derived> //curiously recursive template pattern
{
    //virtual 
    void m_vfun()
    {
        cout<<"Derived::m_vfun...\n";
    }
    void func()
    {
    	cout<<"Derived :: function \n"; 
	}
};

//void thiscall m_fun(Base *cosnt this) m_fun()
// void Base::m_fun()
// {
//     (reinterpret_cast<Derived*>(this)) -> m_vfun();
//     //this->m_vfun();
// }    

int main()
{
    Derived dObj;
    // Base bObj;
    dObj.m_fun();
    
//    Base<Base> bobj ;
//    bobj.m_fun();

}
