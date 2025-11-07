#include<iostream>
using namespace std;

class baseClass 
{
    public :
        baseClass()
        {
            cout<<"This is the baseClass constructor \n";
        }
};

class childClass1 : public baseClass
{
    public :
        childClass1()
        {
            cout<<"This is the childClass1 constructor \n";
        }
};

class childClass2 final : public childClass1
{
    public :
        childClass2()
        {
            cout<<"This is the childClass2 constructor \n";
        }
};

class childClass3 final // : public childClass2
{
    public :
        childClass3()
        {
            cout<<"This is the childClass3 constructor \n";
        }
};



int main()
{
    cout<<"This is a program to understand the Final Keyword in c++ \n";

    childClass2 object ;

}