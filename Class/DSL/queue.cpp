#include <iostream>
using namespace std;

class Node 
{
    public :
        Node * prev ;
        int data ;
        Node * next ;

        Node()
        {
            // cout<<"Node class constructor \n";
        }
        Node (Node * args1 , int data_1 , Node * args2) : prev(args1) , data(data_1) , next(args2)
        {

        }

};

class Queue : public Node 
{
    public :
        Node * head ;
        
        int count ;

        Queue() : count(0) , head(nullptr)
        {
            cout<<"Queue Constructor called \n";
        }

        void enqueue(int args )
        {
            if(count==0)
            {
                Node * new_node = new Node( nullptr, args, nullptr );
                head = new_node;
            }
            else{
                Node * ptr = new Node (head , args , nullptr);
                // head->prev = head->next ;
                // head->next=ptr ;
                // head=ptr ;
                head->next=ptr ;
                head=ptr;
            }    
            count++;
        }

        void print_function()
        {
            if(head!=nullptr)
            {
                while(head->prev!=nullptr)
                {
                    cout<<head->data << "   " ;
                    head=head->prev;
                }
                cout<<head->data;
                cout<<endl;

                while(head->next!=nullptr)
                {
                    cout<<head->data << "   " ;
                    head=head->next;
                }
                cout<<head->data;
            }
            cout<<endl;
        }
};

int main()
{
    cout<<"This is the Queue implementation using the circular Queue\n";

    Queue * ptr = new Queue();

    int data ;
    
    cout<<"Enter the input data ..\n";
    cin>>data;
    ptr->enqueue(data);

    cout<<"Enter the input data ..\n";
    cin>>data;
    ptr->enqueue(data);


    cout<<"Enter the input data ..\n";
    cin>>data;
    ptr->enqueue(data);

    cout<<"Enter the input data ..\n";
    cin>>data;
    ptr->enqueue(data);


    cout<<"Enter the input data ..\n";
    cin>>data;
    ptr->enqueue(data);

    ptr->print_function();

}