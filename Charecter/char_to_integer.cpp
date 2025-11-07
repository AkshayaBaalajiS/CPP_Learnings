// Way 1 
// #include<iostream>
// #include<cstdio>

// using namespace std;

// int main()
// {
//     cout<<"This is a program to convert the char to integer\n";
//     char arr[]="Akshaya Baalaji S ";
//     int size = sizeof(arr)/sizeof(arr[0]);
//     for(int i=0;i<size;i++)
//     {
//         printf("%d   " , arr[i]);
//     }
// }


// way 2 
// #include<iostream>
// #include<cstdio>

// using namespace std;

// int main()
// {
//     cout<<"This is a program to convert the char to integer\n";
//     char arr[]="Akshaya Baalaji S ";
//     int size = sizeof(arr)/sizeof(arr[0]);
//     for(int i=0;i<size;i++)
//     {
//         int temp= arr[i];
//         cout<<temp << "  ";
//     }
// }


// way 3
#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    cout<<"This is a program to convert the char to integer\n";
    char arr[]="ABC Akshaya Baalaji S ";
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size;i++)
    {
        int temp= arr[i] - '0';  // proof that we can add or sub the char and store on the int 
        cout<<temp << "  ";
    }
    cout<<endl;
    for(int i=0;i<size;i++)
    {
        int temp= arr[i];
        cout<<temp << "  ";
    }
}