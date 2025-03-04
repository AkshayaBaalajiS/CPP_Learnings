#include<iostream>
using namespace std ;

class A 
{
    public :
        int row ;
        int col ;
        int m_arr[5][5];
        // A(int arg=1 , int arg1=1) : row(arg) , col(arg1)
        // {
        //     cout <<"@ Constructor \n";
        // }
       
        A() ;
        
       
        // A & operator [](int index)
        // {
        //     cout<<"@ A & operator [](int index) : \n" << this->m_arr[index];
        //     return *this ;
        // }

        int * operator [](int index)  ; // subscript operator overloading 

        ~A();
};
A::A() : row (5), col(5)
{
    for(int i=0;i<row ;i++)
    {
        for (int j=0;j<col;j++)
        {
            m_arr[i][j]=j+ i*5;
        }
        cout<<"\n";
    }
}

int * A::operator [](int index)   // subscript operator overloading 
{
    // cout<<"@ A & operator [](int index) : \n" << this->m_arr[index];
    // return (this->m_arr[index]) ;
    return &(this->m_arr[index][0]) ;
}

A::~A()
{
    for(int i=0;i<row ;i++)
    {
        for (int j=0;j<col;j++)
        {
            
            cout<<"A["<<i <<"]["<<j  << "] = "<<m_arr[i][j] << "   ";
        }
        cout<<"\n";
    }
}

int main()
{
    /*
    A object[5][5];
    IN above line object is a 2 dimentional array having 5 one dimentional array 
    and each one dimentional array having 5 element each element of type A
    */
    A object;
    cout<<"\n----------------------------\n";
    cout<<object.m_arr[2][3];
    cout<<"\n----------------------------\n";
    cout<<"\n----------------------------\n";
    cout<< " object.m_arr[2][1]  :" << object.m_arr[2][1] << "\n";
    cout<<"\n----------------------------\n";
    // object.operator[](2).operator[](1);
    cout<<object[2][1]<<"\n";
    cout<<"\n----------------------------\n";
    cout<<"object.operator[](2) [1] = "<< object.operator[](2) [1] <<"\n";
    cout<<"\n----------------------------\n";

    //trying the change of the value in that address :
    object[2][1] = 12343; 
    cout<<"Value of object[2][1] = 12343 is changed " ;
    cout<<"\n----------------------------\n";

    cout<< " object.m_arr[2][1]  :" << object.m_arr[2][1] << "\n";
    cout<<"\n----------------------------\n";
    cout<<"object.operator[](2) [1] = "<< object.operator[](2) [1] <<"\n";
    cout<<"\n----------------------------\n";


    //trying the change of the value in that address by giving another value from the 
    object[2][1] = 12343; 
    cout<<"Value of object[2][1] = 12343 is changed " ;
    cout<<"\n----------------------------\n";

    cout<< " object.m_arr[2][1]  :" << object.m_arr[2][1] << "\n";
    cout<<"\n----------------------------\n";
    cout<<"object.operator[](2) [1] = "<< object.operator[](2) [1] <<"\n";
    cout<<"\n----------------------------\n";
}