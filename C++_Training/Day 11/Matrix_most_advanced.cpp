#include <iostream>
using namespace std;
#define ROW 4
#define COL 4
 
 
class A{
   
    int m_arr[ROW][COL];
    public :
        A();
        ~A();
        class Helper{
            A * m_p ;
            int rIndex ;
            public:
                Helper (A *p , int ri ) : m_p(p) , rIndex(ri) {}
                int  operator [] (int col_index)
                {
                    cout<<"int ::A ::HElper ::operator [] (int col_index) : col_index "<<col_index<<"\n";
                    return (this->m_p->m_arr [this->rIndex][col_index]);
                }
        };
    Helper operator[] (int row_index);
};
 
A::A()
{
    for(int i=0;i<ROW ;i++)
    {
        for (int j=0;j<COL;j++)
        {
            m_arr[i][j]=j+ i*5;
        }
        cout<<"\n";
    }
}
 
A::Helper  A::operator[] (int row_index)
//Return type  function     argument 
{
    cout<<"A::Helper A :: operator[] (int row_index) "<<row_index<<"\n";
    return Helper(this,row_index);
}
 
A::~A()
{
    for(int i=0;i<ROW ;i++)
    {
        for (int j=0;j<COL;j++)
        {
           
            cout<<"A["<<i <<"]["<<j  << "] = "<<m_arr[i][j] << "   ";
        }
        cout<<"\n";
    }
}
int main()
{
    A obj;
    cout<< "obj[2][1]    :" << obj[2][1] << " \n";
   
} 
 