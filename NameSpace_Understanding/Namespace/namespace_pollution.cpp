
// the below is the error code because fo the ambiguity 
// #include <iostream>
// #include <algorithm>
// #include<vector>
// using namespace std;
// template <typename t1>
// int distance(t1 a ,t1  b )
// {
//     return b-a;
// }
// int main()
// {
//     using namespace std;
//     vector<int> vec ={1,2,3,4,5,6};
//     int dist = distance(vec.begin(),vec.end()); // overloaded ambiguity error 

//     cout<<"The distance is : " << dist << endl;
    
// }

// Try 2 
// here also error because the compiler sees the function def with the std even is we dont use the std  
// #include <iostream>
// #include <algorithm>
// #include<vector>
// // using namespace std;
// using std::cout; // this helps in avoiding the std::cout at time of printing 
// using std::vector; // this helps in avoiding the std::vector at time of creation 


// template <typename t1>
// int distance(t1 a ,t1  b )
// {
//     cout<<"Our function \n";
//     return b-a;
// }
// int main()
// {
//     using namespace std;
//     vector<int> vec ={1,2,3,4,5,6};
//     int dist = std::distance(vec.begin(),vec.end()); // now no ambiguity because we are using the std::distance  

//     int cust_dist = distance(vec.begin(),vec.end()); // now no ambiguity because we are using the std::distance  

    
//     cout<<"The distance is : " << dist << endl;
//     cout<<"The custom distance is : " << cust_dis << endl;
    
    
// }


// Try 3 
// no error code 
#include <iostream>
#include <algorithm>
#include<vector>
// using namespace std;
using std::cout; // this helps in avoiding the std::cout at time of printing 
using std::vector; // this helps in avoiding the std::vector at time of creation 

namespace Akshay
{
    template <typename t1>
    int distance(t1 a ,t1  b )
    {
        cout<<"Our function \n";
        return b-a;
    }
}

int main()
{
    using namespace std;
    vector<int> vec ={1,2,3,4,5,6};
    int dist = std::distance(vec.begin(),vec.end()); // now no ambiguity because we are using the std::distance  

    int cust_dist = Akshay::distance(vec.begin(),vec.end()); // now no ambiguity because we are using the std::distance  

    
    cout<<"The distance is : " << dist << endl;
    cout<<"The custom distance is : " << cust_dist << endl;
    
    
}