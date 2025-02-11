#include<iostream>
using namespace std;

void * function_to_do_nothing();

//gv is a Global Variable that will get stored on the Data Segment under Uninitialized part  on (Block Started by Symbol) which will alocate default value to it  
int gv ; 

// gv_1 is a Global Variable that will get stored in the Data Segment under Initialized part on ( Read / Write ) 
int gv_1 = 10 ;

// gv_2 is a Global Variable that will get stored in the Data Segment under Initialized part on ( Read Only ) 
const int gv_2 = 20 ;

// sv is a Global Variable that will get stored in the Data Segment under Initialized part on (Static Segment) 
static int sv= 20 ;


// machine instruction of the main will be stored on the code segment 
int main()
{
    cout<<"This is a program to show which will get stored where \n";

    // lv is the local variable that will get stored on the stack 
    int lv ;

    // sv_1 is a Static Variable that will get stored in the Data Segment under Initialized part on (Static Segment) 
    static int sv= 20 ;


    // ptr is a variable of type int * that will get stored on the stack segement 
    int * ptr ;

    // ptr_1 is a variable of type int * that will get stored on the Heap segement due to new keyword  
    int * ptr_1 = new int ;

    // ptr_2 is a variable of type int * that will get stored on the Heap segement due to malloc keyword  
    int * ptr_2 = (int *)malloc(sizeof(int *)) ;

    // ptr_3 is a variable of type int * that will get stored on the Heap segement due to calloc keyword  
    int * ptr_3 = (int *)calloc(5,sizeof(int *)) ;

    // ptr_3 is a variable of type int * that will get stored on the Heap segement due to realloc keyword  
    ptr_3= (int *)realloc(ptr_3,sizeof(int *)) ;

    // this will get stored on the stack and a seperate stact frame will be created for argument and return 
    function_to_do_nothing();



}

// Below fucntions machine instruction stored on the code segment and the local variable created inside will be stored in the stack segment 
void * function_to_do_nothing()
{
    cout<<"This is a function to do nothing \n";
    // lv is the local variabel stroed in the stack segment 
    int lv;

    // each time it create a new stack frame 
    for (;gv_1==0;gv_1--)
    {
        function_to_do_nothing();  // this recursive function call stores stack
    }
    return nullptr ;
}