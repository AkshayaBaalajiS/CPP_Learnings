 
#include<iostream>
#include<math.h>
using namespace std ;
double volume_of_sphere(double a )
{
    return (1.33)*(3.14)*(a)*(a)*(a);
}
int volume_of_cube(int a )
{
    return (a)*(a)*(a);
}
double volume_of_cylinder(int a , int b )
{
    return ((3.14)*(a*a) *(b));
}
int main()
{
    cout<<"Calculate the volume of a sphere :  ";  
    cout<<"------------------------------------------------- \n";
    cout<<"Input the side of a sphere  " ;
    int side ;
    cin>>side;
    cout<<"The volume of a sphere is  : " <<volume_of_sphere(side);

    cout<<"\nCalculate the volume of a cube :  ";  
    cout<<"------------------------------------------------- \n";
    cout<<"Input the side of a cube  " ;
    cin>>side;
    cout<<"The volume of a cube is  : " <<volume_of_cube(side);
   
    cout<<"\nCalculate the volume of a cylinder : \n"; 
    cout<<"---------------------------------------------------------- \n";
    cout<<"Input the radius of the cylinder :  : " ;
    int radius ;
    cin>>radius; 
    cout<<"Input the height of the cylinder :  ";
    int height;
    cin>>height;
    cout<<"The volume of a cylinder is : " << volume_of_cylinder(radius,height) ;
}


