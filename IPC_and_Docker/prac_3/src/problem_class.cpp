#include "problem.h"

Problem::Problem()
{
    cout<<"Problem class constructor \n";
}


Problem::~Problem()
{
    cout<<"Problem class destructor \n";
}


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