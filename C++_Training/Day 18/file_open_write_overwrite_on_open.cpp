//Overwrite in file 
#include<iostream>
#include<fstream>
using namespace std ;
int main()
{
	ofstream file_operation;
	file_operation.open("file_1.txt");
	string str  ;
	while(file_operation)
	{
		cout<<"Enter something to append to file :";
		getline(cin,str);
		
		if(str == "break")
		{
			break;
		}
//		file_operation<<str ; // without \n everything get appended on single line itself 
		file_operation<<str<<"\n";
	}
	file_operation.close();
}
