#include <iostream>
#include <list>
using namespace std;

int main()
{
	cout<<"This is the code to understand the list STL in cpp\n";
	list<int> list1;
	cout<< " --- Insertion --------------------\n";
	list1.push_back(12); // 12
	list1.push_back(13); // 12 13 
	list1.push_back(14); // 12 13 14
	list1.push_back(15); // 12 13 14 15
	list1.push_front(11); // 11 12 13 14 15

	for(auto i : list1)
	{
		cout<< i << " ";
	}
	cout<<endl;
	cout<< " -----------------------------------\n";
	
	cout<< " --- Deletion --------------------\n";
	list1.pop_front();// 11
	list1.pop_front();// 12
	list1.pop_back(); // 15
	list1.pop_back(); // 14
	
	for(auto i : list1)
	{
		cout<< i << " ";
	}
	cout<<endl;
	cout<< " -----------------------------------\n";


	cout<< " --- Accessing --------------------\n";
	list1.push_back(12); // 
	list1.push_back(11); // 13 12 11 
	list1.push_back(10); // 13 12 11 10
	list1.push_back(9); // 13 12 11 10 9 
	list1.push_front(14); // 14 13 12 11 10 9 

	auto it = list1.begin();
	cout<<"*it - " << *it <<endl;
	// it = it+1 ;// this cant be done cause iterator of list is bidectional and this cant be done 
	cout<<"it+1 - " << *it <<endl;

	// access list 
	int idxToAcc = 3;
	for(int i=0;i<idxToAcc;i++)
	{
		it++;
	}
	cout<<"*it at idx 3 = " << *it<<endl;

	// access list 
	auto new_it_at_idx = next(list1.begin(), idxToAcc);
	cout<<" * new_it_at_idx =  "<< *new_it_at_idx <<endl;
	for(auto i : list1)
	{
		cout<< i << " ";
	}
	cout<<endl;
	cout<< " -----------------------------------\n";


	cout<< " --- Insert and Delete on Spec index through iterator ---\n";
	// IMPORTANT insert and erase at any place
	// inset at specific possition 
	auto newIter = list1.begin();  // 14(iterator) 89 13 12 11 10 9


	int insert = 89; 
	list1.insert(newIter, insert);	 // 89 14(iterator) 13 12 11 10 9 
	cout<<"First level insert : ";
	for(auto i : list1)
	{
		cout<< i << " ";
	}
	cout<<endl;

	newIter++; //// 89 14 13(iterator) 12 11 10 9
	list1.insert(newIter, insert);// 89 14 89 13 12 11 10 9
	cout<<"Second level insert : ";
	for(auto i : list1)
	{
		cout<< i << " ";
	}
	cout<<endl;

	list1.erase(newIter); // 89 14 89 13(iter) 12 11 10 9
	cout<<"First level erase : "; // // 89 14 89  12 11 10 9
	for(auto i : list1)
	{
		cout<< i << " ";
	}
	cout<<endl;
	cout<< " -----------------------------------\n";

	cout<< " --- size and empty -------\n";
	for(auto i : list1)
	{
		cout<< i << " ";
	}
	cout<<endl;
	cout<< " size =  " << list1.size()<<endl;
	cout<< " empty =  " << list1.empty()<<endl;
	
	cout<< " -----------------------------------\n";
}