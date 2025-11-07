#include <iostream>
using namespace std;

int main()
{
	cout<<"istream in c++\n";
	int x ;
	cin >> x; // this cin is a global obj of istream in C++;

	/*
	cin >> x; reads the integer 10.

	But when you hit Enter, a newline character '\n' is left behind in the input buffer.

	So the buffer looks like this after cin >> x;:

	so we use ignore 
	*/
	cin.ignore(); // for discarding the new line from the input 

	// some function from istream which will be useful 
	char c;
	cin.get(c);

	cout<<"Int  = " << x <<endl;
	cout<<"Char = " << c <<endl;

	cin.ignore(1000, '\n');
	/*
	Step 1: After cin >> num
	User input:
	123⏎
	cin >> num reads the number 123.
	Leftover in the buffer:
	\n

	Step 2: After cin.ignore(1000, '\n')
	ignore(1000, '\n') starts reading the buffer character by character.
	It sees '\n' immediately → stops ignoring.
	Buffer now:
	(empty)

	Only 1 character was ignored, not 1000. ✅
	Step 3: cin.get(c) reads next input
	Buffer is empty, so cin.get(c) waits for the user to type a character.
	Suppose user types A + Enter:

	*/

	string strr;
	cin>>strr;


	cout<<strr<<endl;

	cin.ignore(10000, '\n'); // when we are giving the string with space in string input with cin the string befoe space will be taked and rem will be passed to next input so for clearing buffer we are giving it

	getline(cin,strr);
	cout<<strr<<endl;
}