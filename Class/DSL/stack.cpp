#include<iostream>

using namespace std;

class Node
{
    
    public :
        int data;
        Node * next ;
        Node ()
        {
        }
        Node(int data_1 , Node * ptr) : data(data_1) , next(ptr)
        {
            // cout<<"Node class constructor \n";
        }
};

class LinkedList : public Node 
{
    public :
        Node * head ;
        LinkedList()
        {
            cout<<"LinkedList class constructor called \n";
        }

        void enqueue (int args )
        {   
            Node * new_node = new Node(args , head);
            head = new_node ;           
            cout<<"Enqueue done ..\n";
        }

        void print_function()
        {
            cout<<"............. Print Function ...............\n";     
            Node * temp  = head ;
            while (temp->next != nullptr)
            {
                cout <<  temp->data << "   ";
                temp=temp->next;
            }
            cout<<temp->data << endl;           
        }

        void dequeue ()
        {
            head=head->next;
            cout<<"Dequeue Done \n";
        }
    
};

int main()
{
    cout<<"This is the program to understand Stack implementation using the LinkedList\n";
    LinkedList * ptr =new LinkedList();

    int input_data ;

    cout<<"Enter the data  :  ";
    cin>>input_data;
    ptr->enqueue(input_data);

    cout<<"Enter the data :  ";
    cin>>input_data;    
    ptr->enqueue(input_data);

    cout<<"Enter the data :  ";
    cin>>input_data;    
    ptr->enqueue(input_data);

    cout<<"Enter the data :  ";
    cin>>input_data;    
    ptr->enqueue(input_data);

    ptr->print_function();

    ptr->dequeue();
    ptr->print_function();

    ptr->dequeue();
    ptr->print_function();


    cout<<"Enter the data :  ";
    cin>>input_data;    
    ptr->enqueue(input_data);

    cout<<"Enter the data :  ";
    cin>>input_data;    
    ptr->enqueue(input_data);

    ptr->print_function();
    
}