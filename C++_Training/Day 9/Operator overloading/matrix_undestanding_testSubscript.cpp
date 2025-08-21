#include <iostream>
using namespace std;

int arr[] = { 10, 20, 30 ,40 ,50};

int * gfun(){
    return &arr[0]; // return arr;
}

int main(){
    cout<< gfun()[2] << "\n";
}