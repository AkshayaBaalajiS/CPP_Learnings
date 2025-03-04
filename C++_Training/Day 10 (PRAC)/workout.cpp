#include<iostream>
#include<cstring>
using namespace std;

class MyString{
    private:
        char *m_p;
    public:
        
        MyString():m_p(NULL){}; // default constructor 
        explicit MyString(const char *ptr); // single parameterized constructor 
        explicit MyString (MyString &); // copy constructor 

        MyString & operator = (MyString & rhs); // assignment operator overloading 
        MyString & operator + (MyString &rhs); // + operator overloading 
        
        // ~MyString();
        void display(); 
        friend ostream & operator << (ostream & os,MyString & rhs);
};
ostream & operator << (ostream & os,MyString & rhs)
{
    cout<<rhs.m_p;
    return os ;
}
MyString::MyString (MyString & ref )
{
    this->m_p = ref.m_p ;
}

MyString::MyString(const char *ptr)
{
    if(ptr)
    {
        m_p=new char[strlen(ptr)+1];
        strcpy(m_p,ptr);
    }
    else{
        m_p=NULL;
    }
}
MyString temp; // global 
MyString & MyString :: operator + (MyString & rhs)
{
    int len1=strlen(this->m_p);
    int len2=strlen(rhs.m_p);
    cout<<"len1= "<<len1<<", len2 = "<<len2<<"\n";
    char *cp=new char[len1+len2+1];
    int index=0;
    for(int i=0;i<len1;i++)
        cp[index++]=this->m_p[i];
    for(int i=0;i<len2;i++)
        cp[index++]=rhs.m_p[i];
    cp[index++]='\0';
    cout<<"cp="<<cp<<"\n";
    cout<<"------------------";
    temp.m_p=cp;
    cout<<"---------------------";
    cout<<"-------------";
    return temp;
}


MyString & MyString :: operator = (MyString & rhs)
{
    this->m_p=rhs.m_p;
    return *this;
}

int main()
{
    cout<<"---------------------------------.\n";
    MyString str5("Hello");
    MyString str6("World");
    cout<<"---------------------------------.\n";
    MyString str8;
    str5+str6;
    str8=str5+str6; // + operator and = operator overloading 
    cout<<str8; // << operator overloading 
    cout<<"---------------------------------.\n";
}