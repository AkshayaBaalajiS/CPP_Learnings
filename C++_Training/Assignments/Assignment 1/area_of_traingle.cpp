#include<iostream>
#include<math.h>
using namespace std ;
int area_of_rec(int a , int b )
{
    return (a)*(b);
}
int perimeter_of_rec(int a , int b )
{
    return ((a*2)+(b*2));
}
double area_of_trai(int a,int b , int c )
{
    double s = (0.5)*(a+b+c);
    s = sqrt(s*((s-a )+ (s-b) + (s-c)));
    return s;
}
int main()
{
    cout<<"Find the Area and Perimeter of a Rectangle : ";  
    cout<<"------------------------------------------------- \n";
    cout<<"Input the length of the rectangle : " ;
    int length ;
    cin>>length;
    cout<<"Input the width of the rectangle : " ;
    int width ;
    cin >> width ;
    cout<<"The area of the rectangle is : "  << area_of_rec(length , width) <<"\n" ; 
    cout<<"The perimeter of the rectangle is : "<< perimeter_of_rec(length,width) <<"\n" ;  
    cout<<"Find the area of any triangle using Heron's Formula : \n"; 
    cout<<"---------------------------------------------------------- \n";
    cout<<"Input the length of 1st side of the triangle : " ;
    int side1 ;
    cin>>side1; 
    cout<<"Input the length of 2nd side of the triangle : ";
    int side2;
    cin>>side2;
    cout<<"Input the length of 3rd side of the triangle : " ;
    int side3;
    cin>>side3; 
    cout<<"The area of the triangle is : " << area_of_trai(side1,side2,side3) ; 
}


