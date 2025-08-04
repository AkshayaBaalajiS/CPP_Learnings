#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

#define ASSERT assert 

class Problem
{
    public :
        vector<int> vec_int;
        Problem();
        ~Problem();
};


vector<int> operator + (vector<int > vec_int , vector<int>  rhs );