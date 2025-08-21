#include<iostream>
using namespace std ;

class A
{
    //the below is for trying that the objects can accesss the private member of the class
    void pri_feature_1()
    {
        cout<<"This is the Feature 1 \n";
    }
    public :
        A()
        {
            cout<<"@ A constructor ";
        }
        void feature_1()
        {
            cout<<"This is the Feature 1 \n";
        }
        ~A()
        {
            cout<<"@A Destructor ";
        }
};
class B
{
    public :
        A object_b;
        B()
        {
            cout<<"@ B constructor ";
        }
        void feature_2()
        {
            cout<<"This is the Feature 2 \n";
        }
        ~B()
        {
            cout<<"@B Destructor ";
        }
};


int main()
{
    B object ;
    cout<<"---------------------------------\n";
    object.feature_2();
    cout<<"---------------------------------\n";
    object.object_b.feature_1();
    cout<<"---------------------------------\n";
    // object.object_b.pri_feature_1();  //this error proves the private data member or the member function cant be accessed  
    cout<<"---------------------------------\n";
    
}