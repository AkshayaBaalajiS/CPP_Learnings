#include<iostream>
#include<set>
using namespace std;
class Sett
{
    set<int> variable ;
    public :
        void menu();
        void insert_function()
        {
            cout<<"-------------------------------\n";
            cout<<"void insert_function()  \n";
            cout<<"Enter the value to insert   :";
            int value ;
            cin>>value ;
            this->variable.insert(value);
            cout<<"Inserted ...........\n";
            cout<<"-------------------------------\n";
        }
        void display_function()
        {
            cout<<"-------------------------------\n";
            cout<<"void display_function()  \n";
            for(auto iterate : this->variable)
            {
                cout<<"Data : " << iterate << "  ,  ";
            }
            cout<<"\n";
            cout<<"-------------------------------\n";
        }
        void copy_function(Sett & ref )
        {
            cout<<"-------------------------------\n";
            cout<<"copy_function(Sett & ref )  \n";
            for(auto iterate : this->variable)
            {
                ref.variable.insert(iterate);
            }
            cout<<"Copied .....\n";
            cout<<"-------------------------------\n";
        }
        void move_function(Sett & ref )
        {
            cout<<"-------------------------------\n";
            cout<<"copy_function(Sett & ref )  \n";
            for(auto iterate : this->variable)
            {
                ref.variable.insert(iterate);
            }
            this->variable.clear();
            cout<<"Moved .....\n";
            cout<<"-------------------------------\n";
        }
};
Sett object1;
void Sett::menu()
{
    cout<<"1.Insert\n2.Display\n3.Copy\n4.Move\nEnter the choice : \n";
    int m_choice ;
    int choice;
    cin>>m_choice;
    switch(m_choice)
    {
        case 1:
            cout<<"Insert on \n0.Object\n1.Object1\nEnter your choice ....:";
            cin>>choice;
            if(!choice)
            {
                insert_function();
            }
            else{
                object1.insert_function();
            }
            break;
        case 2:
            cout<<"Display  \n0.Object\n1.Object1\nEnter your choice ....:";
            cin>>choice;
            if(!choice)
            {
                display_function();
            }
            else{
                object1.display_function();
            }
            break;
        case 3:
            cout<<"Copy from \n0.Object\n1.Object1\nEnter your choice ....:";
            cin>>choice;
            if(!choice)
            {
                copy_function(object1);
            }
            else{
                object1.copy_function(*this);
            }
            break;
        case 4:
            cout<<"Move from \n0.Object\n1.Object1\nEnter your choice ....:";
            cin>>choice;
            if(!choice)
            {
                move_function(object1);
            }
            else{
                object1.move_function(*this);
            }
            break;
        default:
            cout<<"ENter the value properly ....\n";
            break;
    }
}
int main()
{
    cout<<"Hi..................\n";
    Sett object ;
    while(1)
    {
        object.menu();
    }
}