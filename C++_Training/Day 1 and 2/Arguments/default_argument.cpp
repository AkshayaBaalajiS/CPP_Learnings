#include<stdio.h>
#include<iostream>

using namespace std ;
//The default argument should be at the end or else while callign the function  
//the argument towards side of the default argument must be properly assigned 
// the z=102 is the default argument in this case 
void gfun(int x , int y , int z=102 )
{
    cout <<"x "<< x <<"\nY " << y <<"\nz "<<z;
}

int main()
{
    gfun(12,23,34); // function call 
    // when we have a function call with no argument it is decorated as gfunv (gfun)iii int argument 
    // when we pass only 2 argument the value so the third is from the compiler side 
    cout<< "\n";
    gfun(44,54);
    // when we have a function call with no argument it is decorated as gfunv (gfun)ii700 int argument 
    // When we pass only 2 argument it get value from the argument when the funtion is created 

}