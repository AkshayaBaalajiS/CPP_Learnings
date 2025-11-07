#include<stdio.h>
#include<stdarg.h>

//elipses 
void gfun(int n , ...);

void main()
{
    printf("gfun(1,10) : \n " );
    gfun(1,10);
    
    printf("gfun(1,20,10) : \n " );
    gfun(2,20,10);

    printf("gfun(3,3,2,1) : \n " );
    gfun(3,3,2,1);
       
}
void gfun(int n ,...)
{
    printf("Total argument passed : %d\n" , n  );
    printf("Trying to print any value from args by address = %d and %d and %d \n" , *(&n+2) ,*(&n+4), *(&n+6) );
    //for accessing the elements 
    //#define va_list (void *)
    //#define va_list (char *) 

    //va_list is a type suitable for holding the information needed to retrieve additional arguments in a variadic function.
    va_list args_list ; // internally of type char * 
    
    int value = 0; 
    //for gfun(4,10,20,30,40) va_start initiaizes the args_list after n that is 10 in this example  
    va_start(args_list,n);

    for(int i=0;i<n ;i++)
    {
        value=va_arg(args_list, int);
        printf("Value = %d and size of it = %d \n" , value, sizeof(value));
    }
    /*
    for (int i = 0; i < n; i++) { value = va_arg(args_list, int); printf("Value = %d and size of it = %d \n", value, sizeof(value)); }

        Iterates three times (n is 3).
        First iteration: value = va_arg(args_list, int); fetches 3.
        Outputs: Value = 3 and size of it = 4
        Second iteration: value = va_arg(args_list, int); fetches 2.
        Outputs: Value = 2 and size of it = 4
        Third iteration: value = va_arg(args_list, int); fetches 1.
        Outputs: Value = 1 and size of it = 4
    */

    // 
    va_end(args_list); // args_list is initialized with NULL 
}
