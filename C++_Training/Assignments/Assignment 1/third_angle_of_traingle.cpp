#include<iostream>
using namespace std ;
void find_third_angle()
{
    cout<<"Find the third angle of a triangle : \n";  
    cout<<"----------------------------------------- \n";
    cout<<"Input\n"; 
    cout<<"the 1st angle of the triangle : " ;
    int first ;
    cin >> first ;
    cout<<"Input the 2nd angle of the triangle : " ; 
    int second;
    cin >> second ;
    cout<<"\n";
    int result ;
    result = 180 - (first + second);
    cout<<"The 3rd of the triangle is : " << result ; 
    
}
int main() {
    find_third_angle();
}