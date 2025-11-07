#include<iostream>
using namespace std ;

class A 
{
    public :
        int row ;
        int col ;
        int m_arr[5][5];
        A() : row (5), col(5)
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
        //the below one will give the address not the value 
        // A & operator [](int index)
        // {
        //     cout<<"@ A & operator [](int index) : \n" << this->m_arr[index];
        //     return *this ;
        // }

        int * operator [](int index)
        {
            // cout<<"@ A & operator [](int index) : \n" << this->m_arr[index];
            return &(this->m_arr[index][0]) ;
        } // this will return the [index][0] address and the [col] is applied in the main function 

        ~A()
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
};
int main()
{
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
}