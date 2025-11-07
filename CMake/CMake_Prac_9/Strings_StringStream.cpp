#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	// Complete this function
    // cout<<str.size()<<endl;
    vector<int> vector_int ;
    string temp="";
    for(int i=0;i<=str.size();i++)
    {
        if(i==str.size())
        {
            // cout<<temp<<"<++"<<endl;
            int number = stoi(temp);
            vector_int.push_back(number);
            temp="";
        }
        else if(str[i]!=',')
        {
            temp =temp +str[i];
            // cout<<i<<"++++"<<endl;
            
        }
        else
        {
            // cout<<i<<"++++"<<endl;
            // cout<<temp<<"<--"<<endl;
            int number = stoi(temp);
            vector_int.push_back(number);
            temp="";
        }        
    }
    
    // vector<int> vec = {1,2,3,4,5};
    return vector_int;
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
