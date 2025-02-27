#include <iostream>
using namespace std;

int main()
{
	cout<<"This is the program for matrix transpose \n";
	int row ;
	cin>>row ;
	int col ;
	cin>>col ;

	int arr[row][col];
	cout<<"Enter the element of the array\n";
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			int temp ;
			cin>>temp;
			arr[i][j]= temp;
		}
	}
	cout<<endl;
	cout<<"Printing the Array :\n";
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			cout<<arr[i][j] << "      ";
		}
		cout<<endl;
	}


	cout<<"After the transpose the matrix is  : \n";
	int another_mar[col][row];
	for(int i=0;i<col;i++)
	{
		for(int j=0;j<row;j++)
		{
			another_mar[i][j] = arr[j][i];

		}
	}

	for(int i=0;i<col;i++)
	{
		for(int j=0;j<row;j++)
		{
			cout<<another_mar[i][j] << "      " ;
		}
		cout<<endl;
	}





}