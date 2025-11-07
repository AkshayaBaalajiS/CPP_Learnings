#include<iostream>
#include<string>

using namespace std ;

int main()
{
    string fname; 
    cout<<"Enter first name : ";
    cin >> fname ;

    char lname[20] ;
    cout<<"\nEnter last name : ";
    cin >> lname ;
    
    //concatenation 
    string full_name = fname+" "+lname ;
    cout << "\nFullName  : " << fname << " " << lname ;
    cout <<"\nConcatenated full name  : " << full_name ;

    //length 
    int count =0 ;
    int char_count = 0; 
    for (int i=0 ; full_name[i]!='\0' ; i++ )
    {
        ++count;
    }
    // for(int i=0 ; lname[i]='\0';i++)
    // {
    //     ++char_count;
    // }
    cout<<"\nLength of the string  : " << count;
    // cout<<"\nLength of char array : " <<char_count;

    //copy 
    string full_name_cpy = full_name ;
    cout<<"\nThe copy is " << full_name_cpy ;
    char array2[20];
    for (int i=0 ; full_name[i]!='\0' ; i++ )
    {
        array2[i]=full_name[i];
    }
    cout<<"\nThe copy of string to char array is :  " ; // *array2;
    for(int i=0;i<count;i++)
    {
        cout<<array2[i];
    } 

    cout<<"\nReverse is :" ;     
    //reverse 
    for(int i=count-1;i>0;i--)
    {
        cout<<array2[i];
    } 

    //convert 

    //trim 
    // cout << "Trim String " << full_name[0:4];  this is not working 
    int start =0 ;
    int end = 0 ;
    cout<<"\nEnter the start and end \n";
    cin >> start ;
    cin >> end  ;
    for (int i=start ; i<=end ; i++)
    {
        cout<<full_name[i];
    }
    cout<<"\n";

    //charecter find and replacement 
    char fcharecter ;
    char rcharecter;
    cout<<"\nEnter the charecter to find  and replaced with  \n" ;
    cin >> fcharecter ; 
    cin >>rcharecter ;
    for (int i=0;i<count;i++)
    {
        if(array2[i] == fcharecter )
        {
            array2[i] = rcharecter ; 
        }
    }
    cout<<"\nThe char array after find and replacement is :  " ; // *array2;
    for(int i=0;i<count;i++)
    {
        cout<<array2[i];
    } 

    //search a charecter 
    cout << "Enter a charecter to search  \n " ;
    char charecter ;
    cin >> charecter ;
    cout <<"\nIndex where it occurs  : " ;
    for (int i=0;i<count;i++)
    {
        if(array2[i] == charecter )
        {
            cout<< i ; 
        }
    }

    //sub string 
    for(int i=0;i<count;i++)
    {
        if(array2[i] == lname[i])
        {
            
        }
    }
    

    


}