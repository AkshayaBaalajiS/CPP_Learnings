#include<cstdio>
#include<iostream>
int main()
{
    int i=3 , n=10;
    printf("Print=%*d\n" , i , n);

    int arr[]={1,2,3,4,5};
    int k=2 , l=3;
    arr[k,l] =100; // here the usage of , operator : comma operator first k but it will lastly point to l
    for(int i=0;i<5;i++)
    {
        printf("%d  " , arr[i]  );
    }
}