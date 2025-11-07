#include<iostream>
using namespace std ;
class Tree 
{
	
	public :
		int data ;
		Tree * lc ;
		Tree * rc ;
		Tree(int args,Tree * args2=NULL , Tree * args3=NULL ) : data(args) , lc(args2) , rc(args3)
		{
			
		}
};

void insert_node(Tree ** ptr )
{
	cout<<"--------------------------------------------------------\n";
	int value ;
	if(!(*ptr)) // checking the address is NULL 
	{	
		cout<<"void insert_node()  \n";
		cout<<"Enter the value : ";
		cin>>value; 
		(*ptr) = new Tree(value );
		(*ptr)->lc = NULL;
		(*ptr)->rc= NULL;
		cout<<"Inserted ........\n";
	}
	else if ((*ptr)->data > value  )
	{
		insert_node(&((*ptr)->lc));		
	}
	else
	{
		insert_node(&((*ptr)->rc));
	}
	cout<<"--------------------------------------------------------\n";
}

void delete_node()
{
	
}

void inorderTraversal(Tree *ptr ) //Perform in-order traversal of the BST.
{
	/*
	Traverse left sub tree 
	Visit the node 
	Traverse right subtree 
	*/
	if(ptr)
	{
		inorderTraversal((ptr)->lc);
		cout<<"--" << (ptr)->data <<"--   " ;
		inorderTraversal((ptr)->rc) ;    	
	}
	
}

void preorderTraversal(Tree * ptr ) //Perform pre-order traversal of the BST.
{
	if(ptr)
	{
		cout<<"--" << (ptr)->data <<"--   " ;
		inorderTraversal((ptr)->lc);
		inorderTraversal((ptr)->rc) ;    	
	}
	
}
void postorderTraversal(Tree * ptr ) //Perform post-order traversal of the BST.
{
	if(ptr)
	{
		inorderTraversal((ptr)->lc);
		inorderTraversal((ptr)->rc) ;    
		cout<<"--" << (ptr)->data <<"--   " ;	
	}
	
}
void traverse (Tree * obj)
{
	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	int choice ;
	cout<<"1.InOrder Traversal \n2.PreOrder Traversals \n3.PostOrder Traversal \nEnter your choice .. : ";
	cin>>choice ;
	switch(choice)
	{
		case 1:
			inorderTraversal(obj);
			break;
		case 2:
			preorderTraversal(obj);
			break;
		case 3:
			postorderTraversal(obj);
			break;
			
			
			
	}	
	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	
}


int main()
{
	Tree * object =NULL;
	while(1)
	{
		cout<<"1.Insertion\n2.Deletion\n3.Traversal\nEnter your choice ..: " ;
		int choice ;
		cin >> choice ;
		switch(choice)
		{
			case 1 :
				insert_node(&object);
				break;
			case 3:
				traverse(object);
				break;
			default :
				cout<<"Enter your choice correctly\n";
				break;
		}
	}
	
}
