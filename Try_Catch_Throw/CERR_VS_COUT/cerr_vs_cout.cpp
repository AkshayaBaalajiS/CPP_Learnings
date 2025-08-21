#include<iostream>

using namespace std;

int main()
{
    cout<<"This is the program to understand the cerr vs cout diff \n";
    /*
    The difference between cerr and cout in C++ lies in their purpose and usage. Both are streams used for output, but they serve different roles:

    1. cout (Character Output Stream)
    Purpose: Used for standard output. Typically, it's used for printing regular output or results that you want to show to the user.
    Stream: It is connected to the standard output stream (stdout), which typically corresponds to the console or terminal window.
    Buffering: cout is buffered, meaning that the output is stored in a buffer before being written to the console. This improves performance because it minimizes the number of actual writes to the console. The buffer is flushed (written to the console) when it's full, when the program finishes, or when std::endl is used.

        std::cout << "This is a regular output message." << std::endl;

    2. cerr (Character Error Output Stream)
    Purpose: Used for error messages and diagnostic information. It is intended for outputting errors, warnings, or anything that is not part of the normal program flow.
    Stream: It is connected to the standard error stream (stderr), which is also typically the console or terminal window, but it is separated from the standard output.
    Buffering: cerr is unbuffered, meaning that each output operation is immediately written to the console without being stored in a buffer first. This ensures that error messages are shown to the user immediately, which is especially important in debugging or error handling.

        std::cerr << "This is an error message!" << std::endl;
    
    
    Key Differences:
    Buffering:
        cout is buffered, so its output is delayed and may not appear immediately.
        cerr is unbuffered, so its output appears immediately.

    Purpose:
        cout is for regular output, such as program results or user prompts.
        cerr is for error messages and diagnostic output.

    Redirection:
        You can redirect cout and cerr to different destinations, such as files or network sockets, but they are often kept separate for clarity. Errors and regular output are often handled separately, so it makes sense to keep cerr for errors and cout for regular program output.

    akshayabaalaji-s@40475-016661:~/GITREPO$ ./a.out > output.txt 2> cerr.txt

    */


    for(int i=0;i<10;i++)
    {
        cout<<"This is the output stmt from the cout " << i <<endl;
    }

    for(int i=0;i<10;i++)
    {
        cerr<<"This is the output stmt from the cerr " << i <<endl;
    }

    
}
