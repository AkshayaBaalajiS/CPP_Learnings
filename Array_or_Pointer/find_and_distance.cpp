#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[5] = {1, 3, 6, 2, 9};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Search an element 6
    auto it = find(arr, arr + n, 4);

    // Print index
    int ind=distance(arr, it);
    cout << ind<<endl;
  

    // vector  
    vector<int> v = {1, 3, 6, 2, 9};

    // Search an element 6
    auto itt = find(v.begin(), v.end(), 6);

    // Print index
    int indes=distance(v.begin(), itt);
    cout << indes;
  

    return 0;
}
