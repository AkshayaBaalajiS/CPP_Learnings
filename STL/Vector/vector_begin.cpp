#include<iostream>
#include<vector>
using namespace std;

int main()
{
    cout<<"This is the program to understand the vecrtor erase operation \n";
    vector<int> vec={1,2,3,4,5,6,7,8,9};
    // vector<int> vec_1(1,2,3,4,5,6,7,8,9); // this is the proof that the vector cant be initialized like this
    // vec.erase(vec.begin()+2,vec.begin()+5);
    vec.erase(vec.begin(),vec.begin()+5);
    // vec.erase(vec.begin());  // this proves the begin is in the start position 
    for(int i: vec)
    {
        cout<< i<< "  " ;
    }
    cout<<endl;

}
// 1   2   3   4   5   6    7    8    9 
// 0   1   2   3   4   5   6    7    8          
// b               b+5 