#include<iostream>
using namespace std;
int main()
{
    cout<<"This is the program to understand the atoi and stoi in cpp \n";
    string str ="123";

    int number  = stoi(str.c_str());
    cout<<"The number is  : " << number << endl;

    int div=1;
    int number_1=0;
    for(int i=0;i<str.size()-1;i++)
    {
        div = div*10 ;
    }
    for(int i=0;i<str.size();i++)
    {
        int tmep = str[i] - '0';
        number_1= number_1 + (tmep * div) ;
        div = div/10 ;
    }
    cout<<"number_1 : " << number_1 <<endl <<endl<<endl; 

    string str_1 = "2009, GeeksforGeeks_founded";
	string str1 = "0x6C1";
	string str2 = "-10010010101";

	// Calling stoi() for all strings.
	int num = stoi(str_1);
	int num_hexa = stoi(str1, nullptr, 16);
	int num_binary = stoi(str2, nullptr, 2);

	// printing converted values
	cout << str_1 << ": " << num << endl;
	cout << str1 << ": " << num_hexa << endl;
	cout << str2 << ": " << num_binary << endl;

}