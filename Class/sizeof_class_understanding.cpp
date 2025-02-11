#include<iostream>
using namespace std ;

class emptyClass
{
    public :
        emptyClass()
        {
            cout<<"This is the default constructor of emptyClass automatically called ...\n";
        }
};



class nEmptyClass
{
    private : 
        int variable1;
        int variable2;
        int variable3;
        int variable4;
    public :
        nEmptyClass()
        {
            cout<<"This is the default constructor of nEmptyClass automatically called ...\n";
        }

};

int main()
{
    cout<<"This is the program to understand the size of the class ...\n";

    cout<<"Empty class ...\n";
    cout<<"The size of the class is : " << sizeof(emptyClass) << "\n";
    emptyClass object;
    cout<<"The size of the empty class object is : " << sizeof(object) << "\n";

    cout<<"------------------------------------------------------------------\n";

    cout<<"Non Empty class ...\n";
    cout<<"The size of the non empty class is : " << sizeof(emptyClass) << "\n";
    nEmptyClass nObject;
    cout<<"The size of the non empty class object is : " << sizeof(nObject) << "\n";
    
}