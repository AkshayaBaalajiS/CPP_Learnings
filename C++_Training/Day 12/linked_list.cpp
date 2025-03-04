#include<iostream>
using namespace std ;
class Node
{
	public :
		int data_node ;	
		Node *ptr ;  // self referencial pointers
		
		Node(int arg , Node * ptr_address ) : data_node(arg) , ptr(ptr_address )  {		}
		~Node() {
			cout<<"@ Node Destructor \n" ;
			if(ptr)
			{
				delete ptr ;
			}
		}
}; 		



class List
{
	public:
	Node * head ;
		List() : head(NULL) 
		{
			cout<<"@ Constructor \n";
		}
		List operator ++ ();
		List operator -- () ;
		List operator -- (int a ) ;
//		int operator [] (List &  ) ;  I thought of doing object[1] mean value of top
		
//		friend void operator = (int & val,List &  ) ;
		friend ostream & operator << (ostream & os , List &rhs ) ;		
		operator int(){
			return this->head->data_node;
		}
};
//Member fucntion definitions   //A::operator ++

// Append 
List List::operator ++ ()
{
	/* THis will create a error when head->next = node_1
	if(head==NULL)
	{
		Node node_1 ; 
		cout<<"Enter a element : \n";
		int ele ;
		cin>> ele ;
		node_1->data_node = ele ;
		node_1.ptr=NULL;
		head->ptr = node_1 ; 
		return *this;
	}
	*/
	cout<<"Enter a element : \n";
	int ele ;
	cin>> ele ;
	head = new Node(ele,head);
	cout<<"Element " << ele << " get pushed ...\n";
	return *this ;	
}

// POP
List List::operator -- ()
{
	if(this->head!=NULL)
	{
		cout<<"List List::operator -- ()  :  \n";
		Node * temp = this->head ;	
		this->head = temp->ptr ;
		cout<<"Poped value is " << temp->data_node <<" \n";
//		delete temp  ;		
	}
	else{
		cout<<"List has no element in it ............. \n";
	}
	return *this;
}

// Delete all / POP all 
List List::operator --  (int a )
{
	if(this->head !=NULL)
	{
		cout<<"List List::operator --  (int a ) ........\n";
		Node * temp = this ->head ;
		cout <<"\nAll data erased .........\n"; 
//		delete temp;
		this->head = NULL ;
	}
	return *this;
}

/*
void operator = (int & val , List & ref  ) 
{
	cout<<"List operator [] (List & ref)   : \n";
//	cout << "The top element in Stack is " << ref.data_node<< " \n";
	val= ref.head->data_node;
}
*/


//print all 
ostream & operator << (ostream & os , List & ref ) 
{
	for(Node *temp =ref.head; temp ; temp=temp->ptr )
	{
		os<<"Value is " << temp->data_node <<" \n";	
	}
//	os << "Value  : " << ref.head->data_node << "  Ptr : " << ref.head->ptr << "\n";
	return os ;
}

int main()
{
	
	
	
	//Object creation 
	List object ;
	int value = -1;
	while(1)
	{
		cout<<"1. Push \n2.Pop \n3.display\n4.Top  \n5.Pop all \nEnter your choice ";
		int choice ;
		cin>>choice ;
		switch(choice)
		{
			case 1:
				++object;
				break;
				
			case 2 :
				--object;
				break;
				
			case 3:
				cout<<object;
				break;
				
			case 4 :
				
				value = object;

				//value = (int) object;
				
				// op = (value, object)
				cout<<"Top of the stack is : "<< value ;
				break;
				
			case 5 :
				object--;
				break;
				
			default:
				cout<<"Enter properly \n";
				break;
		}
	}
	
}