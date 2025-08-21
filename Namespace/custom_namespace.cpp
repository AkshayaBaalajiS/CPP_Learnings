#include<iostream>
using namespace std;

namespace Akshay
{
    int add(int a, int b)
    {
        return a+b;
    }
    int sub (int a, int b)
    {
        return a-b;
    }

}

int main()
{
    int result = Akshay::add(10,34);
    int result_1 = Akshay::sub(10,34);
    cout<<result << "    " << result_1 << endl ;
        
}