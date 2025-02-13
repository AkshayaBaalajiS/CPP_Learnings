// this isa proof that the continuous string input can confuse the input buffer by newline 

// #include<iostream>
// #include<string>
// using namespace std;

// int main()
// {
//     cout<<"This is the program to understand the how we give the char and string input \n";

    
//     int size;
//     cout<<"Enter the size of char array\n";
//     cin>>size ;

 
//     // string input    
    
//     string strname;
//     // getchar();  // if we are reading the input before so for getting the \n because prev cin will give one \n after reading input 
//     cin.ignore();

//     getline(std::cin,strname); // this is how we can get the string input and all space are included until it find the new line 
//     cout<<"The string input \"Akshaya Baalaji Senthilraj \" by getline is : " << strname <<endl;
    
//     cin>>strname; // after first space input ends  
//     cout<<"The string input \"Akshaya Baalaji Senthilraj \" by cin is : " << strname <<endl;


//     // char array input 
    
//     cin.ignore();

//     char name[size];
//     // getchar();  // for getting the \n because prev cin will give one \n after reading input 
    
//     std::cin.getline(name,100);

//     cout<<"The char array input \"Akshaya Baalaji Senthilraj \" by getline is : " << name <<endl;

//     cin>>name;

//     cout<<"The char array input \"Akshaya Baalaji Senthilraj \" by cin is : " << name <<endl;
    

// } 

#include<iostream>
#include<string>
using namespace std;

int main()
{
    cout << "This is the program to understand how we give the char and string input \n";

    int size;
    cout << "Enter the size of char array\n";
    cin >> size;

    // Clear the input buffer to handle newline left after reading the integer
    cin.ignore();  // This will discard the '\n' left in the input buffer after reading size

    // string input using getline (reads entire line with spaces)
    string strname;
    cout << "Enter a string (with spaces): ";
    getline(cin, strname);  // Reads a full line, including spaces
    cout << "The string input by getline is: " << strname << endl;

    // string input using cin (reads only one word before the space)
    cout << "Enter a string (only one word): ";
    cin >> strname;  // Reads only one word, stops at the first space
    cout << "The string input by cin is: " << strname << endl;

    // char array input using getline (reads entire line with spaces)
    char name[size];
    cin.ignore();  // Clear the input buffer again to remove any leftover newline
    cout << "Enter a string (with spaces) for char array: ";
    cin.getline(name, size);  // Reads a full line into the char array
    cout << "The char array input by getline is: " << name << endl;

    // char array input using cin (reads only one word before the space)
    cout << "Enter a string (only one word) for char array: ";
    cin >> name;  // Reads only one word, stops at the first space
    cout << "The char array input by cin is: " << name << endl;

    return 0;
}
