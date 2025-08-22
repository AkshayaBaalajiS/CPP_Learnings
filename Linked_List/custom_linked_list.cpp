#include <iostream>
using namespace std;

class Node
{
	public :
		Node(int some = 0, Node * ptr = nullptr )  
		{
			data=some;
			next = ptr;
		}
		int data;
		Node * next ;
};

class LinkedList 
{
	public:
		Node * LL ;
		
		LinkedList() : LL(nullptr)
		{

		}

		void push_back(int someval)
		{
			if(LL == nullptr)
			{
				LL = new Node();
				LL->data = someval;
				LL->next = nullptr;
			}
			else
			{
				Node * ptr = new Node(someval);
				ptr->next = LL ;
				LL = ptr;
			}
		}

		void print()
		{
			cout<<" --------------------------------------------- \n";
			if(LL!=NULL)
			{
				Node * temp = LL;
				while(temp !=nullptr)
				{
					cout<<"Data = " << temp->data <<endl;
					temp=temp->next;
				}
			}
			else
			{
				cout<<"LinkedList is empty \n";
			}
			cout<<" --------------------------------------------- \n";
		}

		void pop_back()
		{
			if(LL !=nullptr)
			{
				LL = LL->next;
			}
			else{
				cout<<"LinkedLise is empty \n";
			}
		}


};

int main()
{
	cout<<"Linked LIst program \n";

	LinkedList * ptr = new LinkedList ();
	ptr->push_back(123);
	ptr->push_back(234);
	ptr->push_back(345);
	ptr->push_back(456);
	ptr->push_back(567);

	ptr->print();


	ptr->pop_back();
	ptr->print();


	ptr->pop_back();
	ptr->pop_back();
	ptr->print();

	ptr->pop_back();
	ptr->pop_back();
	ptr->pop_back();
	ptr->print();


	




}

