/*
Private members of the class BOOK are 
BOOK NO integer type 
BOOKTITLE 20 characters 
PRICE float (price per copy) 
TOTAL_COST() A function to calculate the total cost for N number of copies 
where N is passed to the function as argument. 
Public members of the class BOOK are 
INPUT() function to read BOOK_NO. BOOKTITLE, PRICE 
PURCHASE() function to ask the user to input the number of copies to be 
purchased. It invokes TOTAL_COST() and prints the total cost to be paid by the user. 
Note : You are also required to give detailed function definitions. 
*/
#include<iostream>
using namespace std ;
class A
{
    int book_no; 
    char booktitle[20]; 
    float price; 
    int total_cost(int n)
    {
        return n * price ;
    }    
    public :
        void get_input()
        {
            cout <<"Enter the Book number :" ;
            cin>> book_no;
            cout<<"Enter the book name : ";
            cin>>booktitle;
            cout<<"Enter the price :";
            cin>>price ;   
        }
        void input_copies()
        {
            cout<<"Enter the number of copies u need : ";
            int copies ;
            cin >>copies;
            cout <<"The amout u have to pay : " << total_cost(copies) << "\n";
             
        }
};

int main()
{
    A object ;
    object.get_input();
    object.input_copies();
}