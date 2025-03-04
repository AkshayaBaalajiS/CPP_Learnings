/*
#include<stdio.h>
#define SQ(x) x*x 
int main()
{
	int i=5 ;
	int j=6 ;
	printf("Hi\n");
	printf("SQ = %d " , SQ(i+j)); // i + j * i + j 
}
O/P : 41 
Explanation // i + j * i + j
#include<stdio.h>
void fucn()
{	
#define TEN 10 // no error the preprocessor fetch the value at first 
	       // error is when we are doing the definition again
}
void use_function()
{
	printf("TEN = %d " , TEN);
}
int main()
{
	printf("Hi");
	printf("\n");
	use_function();
}
O/P : 10 
Explanation : // preprocessor at first define the macros 

*/
#include<stdio.h>
#define TEST(x,y,z) x=100;y=200;z=300
int main()
{
	printf("Hi");
	printf("\n");
	int i=10 , j=20 , k=30 ;
	if(i<5)
		TEST(i,j,k);
	printf("%d %d %d " , i , j , k );
}
