#include<iostream>
using namespace std ;

int main()
{
    cout<<"Check the upper and lower limits of integer : \n";
    cout<<"--------------------------------------------------\n";
    int variable=1;
    long int max;
    long int min;

    for(; variable ; ++variable )
    {
        if((++variable)<=0)
        {
            min=variable;
            max=--variable;
            break;
        }
    }
    cout<<"The maximum limit of int data type : " << max<< "\n";
    cout<<"The minimum limit of int data type : " << min << "\n";

    min=0;
    max=0;
    char variable_1=1;
    for(; variable_1 ; ++variable_1 )
    {
        if((++variable_1)<=0)
        {
            min=variable_1;
            max=--variable_1;
            break;
        }
    }
    cout<<"The maximum limit of char data type : " << max<< "\n";
    cout<<"The minimum limit of char data type : " << min << "\n";

    signed char variable_2=1;
    for(; variable_2 ; ++variable_2 )
    {
        if((++variable_2)<=0)
        {
            min=variable_2;
            max=--variable_2;
            break;
        }
    }
    cout<<"The maximum limit of signed char data type : " << max<< "\n";
    cout<<"The minimum limit of signed char data type : " << min << "\n";

    unsigned char variable_4=1;
    for(; variable_4 ; ++variable_4 )
    {
        if((++variable_4)<=0)
        {
            min=variable_4;
            max=--variable_4;
            break;
        }
    }
    cout<<"The maximum limit of unsigned char data type : " << max<< "\n";
    cout<<"The minimum limit of unsigned char data type : " << min << "\n";


    short variable_3=1;
    for(; variable_3 ; ++variable_3 )
    {
        if((++variable_3)<=0)
        {
            min=variable_3;
            max=--variable_3;
            break;
        }
    }
    cout<<"The maximum limit of short data type : " << max<< "\n";
    cout<<"The minimum limit of short data type : " << min << "\n";
    
    unsigned short variable_5=1;
    for(; variable_5 ; ++variable_5 )
    {
        if((++variable_5)<=0)
        {
            min=variable_5;
            max=--variable_5;
            break;
        }
    }
    cout<<"The maximum limit of unsigned short data type : " << max<< "\n";
    cout<<"The minimum limit of unsigned short data type : " << min << "\n";

    long int variable_6=1;
    for(; variable_6 ; ++variable_6 )
    {
        if((++variable_6)<=0)
        {
            min=variable_6;
            max=--variable_6;
            break;
        }
    }
    cout<<"The maximum limit of long int data type : " << max<< "\n";
    cout<<"The minimum limit of long int data type : " << min << "\n";


    unsigned long int variable_7=1;
    for(; variable_7 ; ++variable_7 )
    {
        if((++variable_7)<=0)
        {
            min=variable_7;
            max=--variable_7;
            break;
        }
    }
    cout<<"The maximum limit of unsigned long int data type : " << max<< "\n";
    cout<<"The minimum limit of unsigned long int data type : " << min << "\n";
}
/*
The maximum limit of int data type : 2147483647 
The minimum limit of int data type : -2147483648 
The maximum limit of unsigned int data type : 4294967295 
The maximum limit of long long data type : 9223372036854775807 
The minimum limit of long long data type : -9223372036854775808 
The maximum limit of unsigned long long data type : 18446744073709551615 
The Bits contain in char data type : 8 
The maximum limit of char data type : 127 
The minimum limit of char data type : -128 
The maximum limit of signed char data type : 127 
The minimum limit of signed char data type : -128 
The maximum limit of unsigned char data type : 255 
The minimum limit of short data type : -32768 
The maximum limit of short data type : 32767 
The maximum limit of unsigned short data type : 65535 
*/