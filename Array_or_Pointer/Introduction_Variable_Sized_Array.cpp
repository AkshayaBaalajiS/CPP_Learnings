#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int input_1, input_2;
    cin>>input_1>>input_2;
    
    vector<vector<int>> vector_of_vector ;
    
    for(int i=0;i<input_1;i++)
    {
        int num_of_ele ;
        cin>>num_of_ele;
        vector<int> ivec ;
                
        for(int k=0;k<num_of_ele;k++)
        {
            int temp ;
            cin>>temp;
            ivec.push_back(temp);
            
        }
        vector_of_vector.push_back(ivec);
    }
    
    for(int i=0;i<input_2;i++)
    {
        int index ;
        cin>>index;
        int col ;
        cin>>col;
        cout<<vector_of_vector[index][col]<<endl;
    }
          
    return 0;
}


// #include <cmath>
// #include <cstdio>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// using namespace std;


// int main() {
//     /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
//     int input_1, input_2;
//     cin>>input_1>>input_2;
    
//     vector<int> vector_i_1 ;
//     vector<int> vector_i_2 ;
    
//     int input_11;
//     cin>>input_11;
//     for(int i=0;i<input_11;i++)
//     {
//         int temp ;
//         cin>>temp ;
//         vector_i_1.push_back(temp);
//     }
    
//     cin>>input_11;
    
//     for(int i=0;i<input_11;i++)
//     {
//         int temp ;
//         cin>>temp ;
//         vector_i_2.push_back(temp);
//     }
    
//     for(int i=0;i<input_2;i++)
//     {
        
        
//     }
    
          
//     return 0;
// }
