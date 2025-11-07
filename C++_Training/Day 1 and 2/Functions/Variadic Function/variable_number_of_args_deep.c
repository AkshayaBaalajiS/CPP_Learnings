#include <stdio.h>
#include <stdarg.h>
#if 0
void gfun(int n,... );

int main()
{
    gfun(0);
    printf("---------------------------------------\n");
    gfun(1,10);
    printf("---------------------------------------\n");
    gfun(2,20,30);
    /*
        push 30
        push 20
        push 2 
        call gfun(int n, ...) // gfuniz
    */
   printf("---------------------------------------\n");
    gfun(3,40,50,60);
}

void gfun(int n, ... ) //2,20,30
{
    va_list al; // #define va_list (void *) 
                // #define va_list (void *) in some compilers

    int iValue = 0;

    printf(" Total args passed are : %d\n",n);

    /*
        va_start macro initialises al with the address of n
        
        al = &n + 1 [OR]
        al = (char *) &n + sizeof(n) // that is sizeof (int n)
    */
    va_start(al,n);
    
    for(int i=0;i<n;i++) //2
    {
        iValue = va_arg(al,int);
        /*
        Step 1:
            a. typecast to  : int *temp = (int *) al
            b. iValue = * temp

        Step 2:
            a. al = al + sizeof(int)
        */
        printf(" iValue = %d\n",iValue);
    }

    va_end(al); //initialises al with NULL
}
#endif

void myPrintf(const char * format, ... );

int main()
{
    myPrintf(" i = %d, d = %f\n",50,5.3);
    // myPrint(" ");
    
}

void myPrintf(const char * format, ...)
{
    va_list al;

    int iValue = 0;
    float dValue = 0.0;
    char * cPtr;

    va_start(al,format);

    for( ; *format; )
    {
        if('%' != *format)
        {
            printf("%c",*format);

        }
        else{
            switch(*++format)
            {
                case 'd':
                    iValue = va_arg(al,int);
                    printf("%d",iValue);
                    break;
                case 'f' :
                    dValue = va_arg(al,double);
                    printf("%f",dValue);
                    break;
                case 's':
                    cPtr = va_arg(al,char *);
                    for( ; *cPtr ; cPtr++)
                    {
                        printf("%c",*cPtr);
                    }
                    break;
            }
        }
    }
}