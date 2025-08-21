#include<iostream>
#include<vector>
using namespace std;

int main()
{
    cout<<"This is the program to understand the vecrtor erase operation \n";
    vector<int> vec={1,2,3,4,5,6,7,8,9};
    // vector<int> vec_1(1,2,3,4,5,6,7,8,9); // this is the proof that the vector cant be initialized like this
    // vec.erase(vec.begin()+2,vec.begin()+5);
    // vec.erase(vec.end()-4,vec.end());
    // vec.erase(vec.end());  // this proves that the end is at next to the last ele 
    vec.erase(vec.end()-1);  // this proves that to remove the last ele we have to do the end()-1 
    // int enddd=vec.end(); // this is the proof the begin and end cant be stored anywhere 
    for(int i: vec)
    {
        cout<< i<< "  " ;
    }
    cout<<endl;

}
// 1   2   3   4   5   6    7    8    9 
// 0   1   2   3   4   5    6    7    8          
//                    e-4                 end