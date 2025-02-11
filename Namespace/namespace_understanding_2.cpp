#include<iostream>

using namespace std;

namespace A{
    // this is a proof that a namespace should not have a cin or cout 
    // cout<<"This is the namespace created for learning\n";
    int varaible;
    // cin>>varaible;

    // namespace should not directly have a function 
    // void funciton_to_print_all(Sample & ref )
    // {
    //     cout<<"Integer variable = " << variable <<endl;
    // }
}
int main()
{
    cout<<"This program is for understanding what not to do with namespace \n";
}

