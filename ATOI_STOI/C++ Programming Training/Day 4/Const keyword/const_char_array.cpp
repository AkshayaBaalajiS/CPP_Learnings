#include <iostream>
using namespace std ;


void print_function(const char * ptr )
{
    cout<< ptr<<"\n" ;
}

void print_function_1( const char ptr[20] ) // this works 
{
    cout<< ptr<<"\n" ;
}

int main()
{
    cout<<"Hello World\n";
    const char arr[] = "Akshaya Baalaji Senthilraj " ;
    print_function(arr);
    print_function_1(arr);

    return 0;
}
/*
#include <iostream>
using namespace std ;


void print_function(char * ptr )
{
    cout<< ptr<<"\n" ;
}

void print_function_1( char ptr[20] ) // this works 
{
    cout<< ptr<<"\n" ;
}

int main()
{
    cout<<"Hello World\n";
    char arr[] = "Akshaya Baalaji Senthilraj " ;
    print_function(arr);
    print_function_1(arr);

    return 0;
}


*/
//Equivalent C
/*
#include <stdio.h>

void int_function(int a , int b )
{
    printf("A = %d  B = %d " , a,b );
}

void print_function(char * ptr )
{
    printf("%s\n" , ptr);
}

void print_function_1(const char ptr[20] ) // this works 
{
    printf("%s\n" , ptr);
}

int main()
{
    printf("Hello World");
    const char arr[] = "Akshaya Baalaji Senthilraj " ;
    print_function("Akshaya Baalaji Senthilraj ");
    print_function_1(arr);
    const int a =10 ;
    const int b =10 ;
    

    return 0;
}
*/