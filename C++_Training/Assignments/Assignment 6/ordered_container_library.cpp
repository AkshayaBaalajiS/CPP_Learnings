/*. Book Class:
o Data Members:
• int bookID: Unique identifier for the book.
• std::string title: Title of the book.
• std::string author: Author of the book.
• bool isAvailable: Availability status of the book

Constructor to initialize the book details.
• Getter methods for book details.
• Method to check availability and set availability status
*/
#include<iostream>
#include<string>
#include <bits/stdc++.h> // for finf fucntion 
#include<vector>
using namespace std;

class Book 
{
	int bookid ;
	string title ;
	string author ;
	bool isavail ; 
	public :
		Book(int args , string args2 , string args3 , bool args4  ): bookid(args) , title(args2) , author(args3) , isavail(args4)
		{
		}
		void getter ( )
		{
//			ref.bookid = this->bookid;
//			ref.title= this->title;
//			ref.author = this->author;
//			ref.isavail = this->isavail;
			cout<<"The Bookid : " << this->bookid << " \n";
			cout<<"The Title : " << this->title << " \n";
			cout<<"The Author : " << this->author << " \n";
			cout<<"The isavail : " << this->isavail << " \n";
		}
		void check_availability()
		{
		}
		void set_availability()
		{
		}
};

/*
Member Class:
o Data Members:
• int memberID: Unique identifier for the member.
• std::string name: Name of the member.
• std::vector<int> borrowedBooks: List of book IDs borrowed by the member.
o Methods:
• Constructor to initialize the member details.
• Method to borrow a book.
• Method to return a book.
• Getter methods for member details

*/
class Member 
{
	int memberid ; 
	string name ;
	vector <int> borrowed_book_id ;
	public :
		Member(int arg , string args1 , vector<int> args2 ) : memberid(arg) , name(args1) , borrowed_book_id(args2) 
		{
		}
		void borrow_book(int bookid)
		{
			cout<<"void borrow_book(int bookid)   : \n";
			cout<<"Member name : " << this->name << "\n";
			this->borrowed_book_id.push_back(bookid);
			cout<<"Borrowed book id is : \n";
			for(auto range_it  : this->borrowed_book_id)
			{
				cout << "Book id : " << range_it	<< "    ";
			}
			cout<<"Book added to the borrowed books of member ..\n";	
		}
		void return_book(int bookid)
		{
			cout<<"void return_book(int bookid)   : \n";
			cout<<"Member name : " << this->name << "\n";
			int pos=0;
			//the below is how u have to delete the element 
			//auto it = find(vector.begin(), vector.end(), valueToBeDeleted);
			
			auto it = find(borrowed_book_id.begin() ,borrowed_book_id.end() ,bookid );
			if(it != borrowed_book_id.end())
			{
				borrowed_book_id.erase(it);
			}
			
			
			cout<<"Book erased from borrowed books of member ..\n";	
		}
		int get_member_id()
		{
			return this->memberid ;
		}
		void  getter ()
		{
//			ref.memberid = this->memberid;
//			ref.name= this->name;
//			ref.borrowed_book_id = this->borrowed_book_id; 
			cout<<"Member id  : " << this->memberid << " \n";
			cout<<"Member Name  : " << this->name << " \n";
//			cout<<"Borrowed Books id  : " << this->borrowed_book_id << " \n";
			for(auto range_it  : this->borrowed_book_id)
			{
				cout << "Book id : " << range_it	<< "    ";
			}			
			cout<<"\n";
		}
};
/*
. Library Class:
o Data Members:
• std::vector<Book> books: Collection of books in the library.
• std::vector<Member> members: Collection of members in the library.
o Methods:
• Method to add a new book.
• Method to add a new member.
• Method to borrow a book.
• Method to return a book.
• Method to display all books.
• Method to display all members.
*/
class Library 
{
	vector<Book> books ; 
	vector<Member> members;
	public :
		void add_book()
		{
			cout<<"**************************************************************\n";
			cout<<"void add_book()    : \n" ; 
			
			cout<<"Enter the bookid : " ;
			int bookid ;
			cin>>bookid ; 
			cout<<"Enter the title : ";
			string title ;
			cin>>title ;
			cout<<"Enter the author : ";
			string author ;
			cin>>author  ;
			cout<<"Enter true or false : ";
			bool isavail ;
			cin>>isavail;
			Book object(bookid , title , author , isavail);
			books.push_back(object);
			cout<<"**************************************************************\n";
		}
		void add_member()
		{
			cout<<"--------------------------------------------------------------\n";
			cout<<"Enter the memberid  : " ;
			int memberid ; 
			cin>>memberid ;
			cout<<"Enter the member name : ";
			string name ;
			cin>>name ;
			cout<<"Enter the number of book borrowed : ";
			int number_of_book_borrowed ;
			cin>>number_of_book_borrowed; 
			vector <int> borrowed_book_id ;
			for(int i=0;i<number_of_book_borrowed ; i++)
			{
				cout << "Enter the book id ..";
				int bookid ;
				cin>>bookid ;
				borrowed_book_id.push_back(bookid); 
			} 
			Member object (memberid , name , borrowed_book_id);
			members.push_back(object);
			cout<<"--------------------------------------------------------------\n";
		}
		void borrow_book()
		{
			cout<<"#############################################################\n";
			cout <<"void borrow_book()       :   \n" ;
			cout<<"Enter the member id : ";
			int mem_id ;
			cin>>mem_id ;
			cout << "Enter the book id ..";
			int bookid ;
			cin>>bookid ;
			for(auto &it : members )
			{
				if(it.get_member_id() == mem_id)
				{
					it.borrow_book(bookid);
//					it.borrowed_book_id.push_back(bookid); because of rpivate this cant be done 
				}
				it.getter();
				
			}
			
			cout<<"#############################################################\n";
			
		}
		void return_book()
		{
			cout<<"#############################################################\n";
			cout <<"void return_book()       :   \n" ;
			cout<<"Enter the member id : ";
			int mem_id ;
			cin>>mem_id ;
			cout << "Enter the book id ..";
			int bookid ;
			cin>>bookid ;
			for(auto &it : members )
			{
				if(it.get_member_id() == mem_id)
				{
					it.return_book(bookid);
//					it.borrowed_book_id.push_back(bookid); because of rpivate this cant be done 
				}
				it.getter();
				
			}
			cout<<"#############################################################\n";
		}
		void display_books()
		{
			cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
			cout<<"void display_books()    : \n";
			for (auto it1 : books)
			{
				cout<<"............................................\n";
				it1.getter(); 
				cout<<"............................................\n";
			}
			cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
		}
		void display_members()
		{
			cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
			cout<<"void display_members()    : \n";
			for (auto it1 : members)
			{
				cout<<"............................................\n";
				it1.getter(); 
				cout<<"............................................\n";
			}
			cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
		}
};
int main()
{
/*
1. Add books to the library.
2. Add members to the library.
3. Borrow books.
4. Return books.
5. Display the list of books.
6. Display the list of members.
*/
	Library object ;
	while(1)
	{	
		cout<<"------------------------------------------------------------------------\n";
		cout<<"1. Add books to the library\n2. Add members to the library.\n3. Borrow books.\n4. Return books.\n5. Display the list of books.\n6. Display the list of members.\nEnter your choice  :" ;
		int choice ;
		cin>>choice ;
		switch(choice)
		{
			case 1:
				object.add_book();
				break;
			case 2:
				object.add_member();
				break ;
			case 3 : 
				object.borrow_book();
				break;
			case 4 : 
				object.return_book();
				break;
			
			case 5:
				object.display_books();
				break;
			case 6 :
				object.display_members();
				break;
		}
	}
}
