#include<iostream>
#include<map>
using namespace std ;

void function_to_print(map<int,string> map_variable)
{
    map<int , string>::iterator iterate= map_variable.begin();
    while(iterate != map_variable.end())
    {
        cout<<"Key  : " << iterate->first << " Value  :  " << iterate->second << "\n";
        ++iterate;
    }
}

int main()
{
    cout<<"This is a program to demonstrate Map \n";
    map<int,string> map_variable ;

    cout<<"Inserting by index (first)  \n";
    map_variable[0]="Akshaya baalaji";
    map_variable[1]="Senthilraj";
    map_variable[2]="Random";
    map_variable[3]="String";
    map_variable[4]="Size_Simple";

    cout<< " ------------------ Printing of the Map ------------------------\n";
    function_to_print(map_variable);
    cout<<"\n";


    cout<< " ------------------ Size Map ------------------------\n";
    cout<<"The size of the map is : " << map_variable.size();
    cout<<"\n";
    cout<<"The Max size of the map is : " << map_variable.max_size();
    cout<<"\n";


    cout<< " ------------------ Empty or not  ------------------------\n";
    cout<<"The Map is empty : " << map_variable.empty();
    cout<<"\n";

    

    cout<< " ------------------ Erase  ------------------------\n";
    cout<<"Erase key 3 : " << map_variable.erase(3);
    cout<<"\n";

    
    
    cout<< " ------------------ Printing of the Map ------------------------\n";
    function_to_print(map_variable);

    cout<< " ------------------ Clear of the Map ------------------------\n";
    map_variable.clear();
    cout<<"Map Cleared ....\n ";


    cout<< " ------------------ Empty or not  ------------------------\n";
    cout<<"The Map is empty : " << map_variable.empty();

    cout<<"\n";
    



    
}