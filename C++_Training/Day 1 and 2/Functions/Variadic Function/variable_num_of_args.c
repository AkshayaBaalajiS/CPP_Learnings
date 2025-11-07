#include <stdio.h>
#include <stdarg.h>

void myPrintf(const char * format, ...);

int main()
{
    myPrintf("i = %d, d = %f\n", 50, 5.3);
    return 0;
}

void myPrintf(const char * format, ...)
{
    va_list al;
    int iValue = 0;
    double dValue = 0.0;  // Changed to double to match va_arg type for %f
    char * cPtr;

    va_start(al, format);

    for (; *format; format++)  // Increment format in the loop
    {
        if ('%' != *format)
        {
            printf("%c", *format);
        }
        else
        {
            switch (*++format)
            {
                case 'd':
                    iValue = va_arg(al, int);
                    printf("%d", iValue);
                    break;
                case 'f':
                    dValue = va_arg(al, double);  // Correct type for %f
                    printf("%f", dValue);
                    break;
                case 's':
                    cPtr = va_arg(al, char *);
                    for (; *cPtr; cPtr++)
                    {
                        printf("%c", *cPtr);
                    }
                    break;
                default:
                    printf("%%");  // Print '%' if an unknown specifier is found
                    format--;  // Adjust format pointer back to '%'
                    break;
            }
        }
    }

    va_end(al);
}
