//Overwrite in file 
#include<iostream>
#include<fstream>
#include<vector>
using namespace std ;
int main()
{
	ofstream file_operation;
	
//	file_operation.open("file_1.txt"); // file opened in overwrite mode 
	file_operation.open("file_1.txt",ios::app); // file opened in append mode 
	
	vector<string> vec_str;
	string str  ;
	while(1)
	{
		cout<<"Enter something to append to vector :";
		getline(cin,str);
		if(str!="break")
		{
			vec_str.push_back(str);
		}
		else{
			break;
		}
		//append to vector 
	}
	
	//print the vector :
	for(auto str_iterator : vec_str)
	{
		cout<<"Data : " << str_iterator <<"\n";
	}
	
	//append the vec to file 
	for(auto iterator : vec_str)
	{
		file_operation<<iterator<<"\n";
	}
	file_operation.close();
}
