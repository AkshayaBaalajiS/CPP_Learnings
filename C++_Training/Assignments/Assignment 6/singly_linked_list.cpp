#include<iostream>
using namespace std ;
class LL 
{
	public :
		int data ;
		LL * next ;
		LL(int args , LL * nxt) : data(args) , next(nxt)
		{
			cout<<"@ LL Constructor \n";
		}
};
class Nodes 
{

	public :
		LL * head ;
		Nodes() : head(NULL) 
		{
			cout<<"@ Nodes Constructor \n";
		}
		void operator ++ () ; 
		void operator -- () ; 
		
		friend ostream & operator << (ostream & os , Nodes & rhs );
		
};

void Nodes::operator ++ ()
{
	cout<<"**************************************************************\n";
	cout<<"@ void Nodes::operator ++ () ...\n";
	cout<<"1.Insert at head \n2.Insert at End \n3.Manual position to insert \nEnter the choice.. ";
	int choice ;
	cin>>choice ;
	int value ;
	LL * temp = NULL ;
	switch(choice)
	{
		case 1:
			cout<<"Inserting @ head " << "\n";
			cout<<"Enter the value : ";
			cin >> value ;
			head =new LL (value , head );
			cout<<"Inserted................\n";
			break;
		case 2 :
			cout<<"Inserting @ end " << "\n";
			cout<<"Enter the value : ";
			cin >> value ;
			temp = head ;
			for( ; (temp->next!=NULL) ; temp=temp->next)
			{
				
			}
			temp->next = new LL(value ,NULL);
			break;
		case 3 :
			cout<<"Enter the position to insert other than head and end  : " ;
			int pos ;
			cin>>pos ;
			temp = head ;
			for( int i = 0  ; i < pos-1 ; i++)
			{
				temp=temp->next ;
			}
			cout<<"Enter the value : ";
			cin >> value ;
			temp->next = new LL (value , temp->next);
			break;
		
		default :
			cout<<"Enter the choice properly....\n"	;
			break;		
	}
	cout<<"**************************************************************\n";	
}

void Nodes::operator -- ()
{
	cout<<"--------------------------------------------------------------\n";
	cout<<"@ void Nodes::operator -- () \n";
	LL * temp = head ;
	cout<<"Enter the position to delete ... : ";
	int pos ;
	cin >> pos ;
	if(pos==0)
	{
		head=head->next;
	}
	else
	{
		for(int i=0;i<pos-1;i++)
		{
			temp=temp->next;	
		}
		temp->next = temp->next->next;
	}
		
	
	cout<<"Deleted .............\n";
	cout<<"--------------------------------------------------------------\n";
	
}

ostream & operator << (ostream & os , Nodes & rhs )
{
	cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	os<<"@ ostream & Nodes::operator << (ostream & os , LL & rhs ) .....\n";
	for(LL * temp = rhs.head ; temp ;  temp=temp->next)
	{
		cout<<"Data : " << temp->data <<"\n";
	}
	cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	return os ;
}


int main()
{
	cout<<"This is Linked List Implementation.....\n";
	cout<<".............................................\n";
	
	Nodes object;
	
	cout<<".............................................\n";
	while(1)
	{
		cout<<"1.Insertion\n2.Deletion\n3.Traversal\nEnter your choice ... : ";
		int choice ;
		cin>>choice;
		switch(choice)
		{
			case 1:
				++object ;
				break;
			case 2:
				--object;
				break;
			case 3 :
				cout<<object;
				break;
		}
	}
	
}

