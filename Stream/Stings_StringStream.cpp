

#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
    // Complete this function
    vector<int> vector_i ;
    string temp = "";
    stringstream ss(str);
    while(getline(ss,temp,','))
    {
        int inte = stoi(temp);
        vector_i.push_back(inte);
    }
    return vector_i;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}



// #include <sstream>
// #include <vector>
// #include <iostream>
// using namespace std;

// vector<int> parseInts(string str) {
//  // Complete this function
//     vector<int> vector_i ;
//         string temp = "";
    
//     for(int i=0;i<=str.size();i++)
//     {
//         if(i==str.size()){
//             int inte =stoi(temp, nullptr, 10);
//             vector_i.push_back(inte);
//             temp="";
//         }
//         else if(str[i]!=',')
//         {
//             temp=temp+str[i];
//         }
//         else {
//             // int inte =stoi(temp);
//             // int inte =stoi(temp);
//             int inte =stoi(temp, nullptr, 10);
            
//             vector_i.push_back(inte);
//             temp="";
//         }
//     }
//     return vector_i;
// }

// int main() {
//     string str;
//     cin >> str;
//     vector<int> integers = parseInts(str);
//     for(int i = 0; i < integers.size(); i++) {
//         cout << integers[i] << "\n";
//     }
    
//     return 0;
// }


// #include <sstream>
// #include <vector>
// #include <iostream>
// using namespace std;

// vector<int> parseInts(string str) {
// 	// Complete this function
//     vector<int> vector_i ;
//         string temp = "";
    
//     for(int i=0;i<=str.size();i++)
//     {
//         if(i==str.size()){
//             int inte =stoi(temp, nullptr, 10);
//             vector_i.push_back(inte);
//             temp="";
//         }
//         else if(str[i]!=',')
//         {
//             temp=temp+str[i];
//         }
//         else {
//             // int inte =stoi(temp);
//             // int inte =stoi(temp);
//             int inte =stoi(temp, nullptr, 10);
            
//             vector_i.push_back(inte);
//             temp="";
//         }
//     }
//     return vector_i;
// }

// int main() {
//     string str;
//     cin >> str;
//     vector<int> integers = parseInts(str);
//     for(int i = 0; i < integers.size(); i++) {
//         cout << integers[i] << "\n";
//     }
    
//     return 0;
// }