#include <iostream> 
#include <vector>
#include <cassert>
using namespace std;

// the below cant be done cause assert is a acro not a function 
// typedef assert ASSERT 


#define ASSERT assert 


class Problem
{
    public :
        vector<int> vec_int;
        Problem()
        {
            cout<<"Problem class constructor \n";
        }


        ~Problem()
        {
            cout<<"Problem class destructor \n";
        }

};


vector<int> operator + (vector<int > vec_int , vector<int>  rhs )
{
    ASSERT(vec_int.size() == rhs.size());
    vector<int> result_vec;
    result_vec.resize(vec_int.size());
    for(int i=0;i<rhs.size();i++)
    {
        result_vec[i] = vec_int[i] + rhs[i];
    }
    return vec_int;
}

int main()
{
    cout<<"This is the program to understand the vector addition, substraction, division, multiplication \n";
    
    Problem obj ;
    
    cout<<"Enter the size of the vector \n";
    int sis;
    cin>>sis;
    obj.vec_int.resize(sis);
    
    for(int i=0;i<sis;i++)
    {
        int tmep;
        cin>>tmep;
        obj.vec_int[i] = sis;
    }
    
    cout<<"Enter the size of the vector 2\n";
    cin>>sis;
    vector<int> vec_int_1;
    vec_int_1.resize(sis);
    
    for(int i=0;i<sis;i++)
    {
        int tmep;
        cin>>tmep;
        vec_int_1[i] = sis;
    }
    
    vector<int> result_t = obj.vec_int + vec_int_1;
 
}

    