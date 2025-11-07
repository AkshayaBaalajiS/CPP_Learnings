#include <iostream>
using namespace std;

struct Base{
    // //void thiscall m_fun(Base *cosnt this) m_fun()
    // void m_fun()
    // {
    //     m_vfun();
    //     //this->m_vfun();
    // }
    
    void m_fun();
    //virtual 
    void m_vfun()
    {
        cout<<"Base::m_vfun..\n";
    }
};

struct Derived : Base
{
    /* data */
    virtual void m_vfun()
    {
        cout<<"Derived::m_vfun...\n";
    }
};

//void thiscall m_fun(Base *cosnt this) m_fun()
void Base::m_fun()
{
    (reinterpret_cast<Derived*>(this)) -> m_vfun();
    //this->m_vfun();
}    

int main()
{
    Derived dObj;
    Base bObj;
    dObj.m_fun();

}
