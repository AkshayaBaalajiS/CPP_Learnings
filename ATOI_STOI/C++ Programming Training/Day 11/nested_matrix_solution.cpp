#include <iostream>
#include<typeinfo>

using namespace std;

class Helper; //this is forward-declaration

class Outer{
    public:
    class Helper {
        public:
        int operator [] (int col_index )
        {
            cout<<"int Helper::operator [] int col_index   " << col_index << "\n";
            return 0;
        }
    };
    Helper operator [] (int row_index)
    {
        cout<<"operator[] (int row_index)"<<row_index<<"\n";
        //return *this;
        return Helper();
    }
};
int main()
{
    Outer o_obj;
    cout<<"typeid(o_obj).name() = "<<typeid(o_obj).name();
    cout<<"--------------------------------------\n";
    Outer::Helper h_obj;
    cout<<"typeid(o_obj).name() = "<<typeid(h_obj).name();
    cout<<"--------------------------------------\n";
        
    cout << "============================" <<o_obj[1][2];
}