// Queue implementation by linked list 
#include<iostream>
using namespace std ;
#define max 5


class Queue
{
	public :
		int data ;
		Queue * next  ;	
		Queue * prev ;
		Queue(int data ,Queue * next , Queue * prev   ) : data (data) , next(next) , prev(prev )
		{
			cout<<"Node created ..........\n";	
		}
};
	
class Nodes 
{
	public :
		Queue * head ;
		static int top ;
		Nodes():head(NULL)
		{
			cout<<"@ Nodes Constructor \n";
		}
		Nodes  operator ++ ();
		Nodes operator -- ();
		Nodes operator --(int a);
		Nodes operator ++(int a);
		friend ostream & operator << (ostream & os , Nodes & ref );
		
		
		~Nodes()
		{
			cout<<"@ Nodes Destructor \n";
		}
};

int Nodes::top = 0;
//Nodes Queue::head = NULL ;



//enqueue 
Nodes  Nodes::operator ++()
{
	if(top==0)
	{
		cout<<"Enter a value \n";
		int value ;
		cin>>value ;
//		Queue * node = head ;
		Queue * node = new Queue(value , NULL , NULL ) ;
		head= node ;
		++top;
//		node->data = value ;
//		node->next=NULL ;
//		node->prev=NULL;
//		head= node ;
		cout<<"Inserted & top =     " << top <<  "  head = "  <<head <<"\n" ;
	}
	else if(top<max)
	{
		cout<<"Enter a value \n";
		int value ;
		cin>>value ;
//		Queue * node = head ;
		
		Queue * node = new Queue(value , head , NULL ) ;
		head->prev=node;
		head= node ;
		++top;
//		node->data = value ;
//		node->next=NULL ;
//		node->prev=NULL;
//		head= node ;
		cout<<"Inserted & top =     " << top <<  "  head = "  <<head  <<"\n"; //<< "  this =  "  << *this  <<"\n" ;
	}
	else
	{
		cout<<"Queue reached max size cant insert ........\n";
	}
	return *this ;
}

//dequeue FIFO 
Nodes Nodes::operator --()
{
	
    if(head->next)
	{
		Queue * temp = head ;
        for(Queue * it =temp ;(it->next!=NULL);it=it->next ,temp=temp->next)
        {
            
        }
        temp->prev->next = NULL ;
        
		cout<<"Popped data is    " << temp->data << "\n";
        delete temp ;
		// head = head->next;
		--top;
		// delete temp ;	
	}
    else if(head->data >=0)
    {
        Queue * temp = head ;
        cout<<"Popped data is    " << temp->data << "\n";
        head= NULL;
        delete temp ;
    }
    else {
		cout<<"Nothing is in Queue \n";
	}
	
	return *this;
}

//Is Empty 
Nodes Nodes::operator --(int a)
{
	if(!head)
	{
		cout<<"Nothing in Queue \n";
	}
	else{
		cout<<"Not Empty .......\n";	
	}
	return *this;
}

//Is Full 
Nodes Nodes::operator ++(int a)
{
	if(top==max)
	{
		cout<<"Queue is FULL......\n";
	}
	else{
		cout<<"Not FULL........\n";	
	}
	return *this;
}

//display 
ostream & operator << (ostream & os , Nodes & ref )
{
	for(Queue * temp = ref.head ; temp ; temp=temp->next)
	{
		os << "data = " << temp->data << " \n";
		
	}
	return os ;
}



int main()
{
	cout<<"Hi ..............\n";
	Nodes object;
	cout<<"..................\n";
	cout<<"Object address is  .... " << &object  << "\n";
	while(1)
	{
		cout<<"1.Enqueue\n2.Dequeue\n3.IsEmpty\n4.IsFull\n5.Display\nEnter your choice :";
		
		int choice ;
		cin>>choice ;
		switch(choice)
		{
			case 1: // enqueue 
				++object;
				break;
			case 2 : 
				--object;
				break;
			case 3: 
				object--;
				break;
			case 4: 
				object++;
				break;
			case 5:// display 
				cout<<object;
				break;
					
		}	
	}	
	
}