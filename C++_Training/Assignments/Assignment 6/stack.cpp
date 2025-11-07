#include<iostream>
using namespace std ;
#define max 5 
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
		static int top ;
		Nodes() : head(NULL) 
		{
			cout<<"@ Nodes Constructor \n";
		}
		//push 
		void operator ++ () ; 
		//pop
		void operator -- () ; 
		//peek
		operator int()
		{
			if(head)
			{
				return head->data ;
			}
		}
		//Is Empty 
		void operator -- (int a) ;
		//Is Full  
		void operator ++ (int a) ; 
		//Fisplay
		friend ostream & operator << (ostream & os , Nodes & rhs );
		
};
int Nodes::top = 0 ;
void Nodes::operator ++ ()
{
	cout<<"**************************************************************\n";
	cout<<"@ void Nodes::operator ++ () ...\n";
	if(top<max)
	{
		cout<<"Inserting @ head " << "\n";
		cout<<"Enter the value : ";
		int value ;
		cin >> value ;
		head =new LL (value , head );
		++top;
		cout<<"Inserted................\n";
	}
	else{
		cout<<"No Insertion possible ...\n";
	}
	
	
	cout<<"**************************************************************\n";	
}
void Nodes::operator ++ (int a )
{
	cout<<"**************************************************************\n";
	cout<<"@ void Nodes::operator ++ () ...\n";
	if(top==max)
	{
		cout<<"The stack is Full .....\n";
	}
	else 
	{
		cout<<"The stack is not full ....\n";
	}
	cout<<"**************************************************************\n";
}
void Nodes::operator -- (int a )
{
	cout<<"**************************************************************\n";
	cout<<"@ void Nodes::operator -- (int a ) ...\n";
	if(head)
	{
		cout<<"The Stack is Not Empty............\n";
	}
	else
	{
		cout<<"The stack is Empty.................\n";
	}
	cout<<"**************************************************************\n";
}

void Nodes::operator -- ()
{
	cout<<"--------------------------------------------------------------\n";
	cout<<"@ void Nodes::operator -- () \n";
	if(top==0)
	{
		cout<<"No element in stack .....\n";
	}
	else if(top==1)
	{
		head=head->next;
		head=NULL;
		--top;
		
		cout<<"Deleted Last Inserted Element .............\n";
	}
	else
	{
		head=head->next;
		--top;
		
		cout<<"Deleted Last Inserted Element .............\n";
	}
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
	int value ;
	while(1)
	{
		cout<<"1.Push \n2.Pop\n3.Peek\n4.IsFull\n5.IsEmpty\n6.Display All Elements in stack \nEnter the choice.. ";
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
				value = object ;
				cout<<"-------------Top of stack is : " << value <<"------------------\n";
				break; 
			case 4:
				object ++ ; 
				break;
			case 5 :
				object -- ;
				break;
			case 6 :
				cout<<object;
				break;
		}
	}
	
}


