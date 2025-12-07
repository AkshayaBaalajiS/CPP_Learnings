#include<iostream>
#include<vector>
using namespace std;

void print_vector(vector<int> vector_variable)
{
    while(!vector_variable.empty())
    {
        cout<< vector_variable.back()<< " " ;
        vector_variable.pop_back(); 
    }
    cout<<"\n";

}

void print_vec_like_array(vector<int> vector_variable)
{
    for (int i=0;i<vector_variable.size();i++)
    {
        cout <<vector_variable[i] << " " ; 
    }
    cout<<"\n";
}

int main()
{
    vector<int> vector_variable ;
    vector_variable.resize(10); // so resize is giving the default value as int 
    print_vec_like_array(vector_variable);

}