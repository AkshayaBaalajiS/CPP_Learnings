#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    cout<<"This is the code to9 explain the diff bet the strcpy and strncpy \n";
    // char * name  = "Akshaya Baalaji Senthilraj";
    /*
    The string "Akshaya Baalaji Senthilraj" is a string literal, which is stored in read-only memory. Attempting to modify this string (as you're doing with memset) 
    will result in undefined behavior and typically cause a segmentation fault because the memory holding the literal is not writable.
    */
   char name[]  = "Akshaya Baalaji Senthilraj";

    string name_1 = "Akshaya Baalaji";

    cout<<"The char []  = " <<name<<endl;
    cout<<"The Sting is  = " << name_1 <<endl;

    memset((void *)name,0,strlen(name));

    cout<<"After memset on char * \n";
    cout<<"The char []  = " <<name<<endl;
    cout<<"The Sting is  = " << name_1 <<endl;

    memcpy(name, name_1.c_str(),name_1.size());


    cout<<"After memcopy on char * \n";
    cout<<"The char []  = " <<name<<endl;
    cout<<"The Sting is  = " << name_1 <<endl;

}