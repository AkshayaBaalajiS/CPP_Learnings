#include <iostream>
using namespace std;

int globalNum =23 ;

void function(const int & number)
{
	cout<<"@ void function()\n";
	// cout before of a error stmt wont be shown 
	// cout << "Number = 0 or not check here "<< (number == 0) ? 1 : 0 ; // this line is not printed cause the prg terminated / crahsed before flush happen
	cerr<< "Number = 0 or not check here "<< (number == 0) ? 1 : 0 ; // this line is not printed cause the prg terminated / crahsed before flush happen
	// cerr flushes immediately, making it suitable for debugging.
	globalNum/= number;

	/*
	try
	{
		globalNum/= number ; // It is crashing because of a hardware-level signal, not a C++ throw.
		
			// CPU detects illegal arithmetic instruction
			// CPU raises hardware interrupt
			// OS converts it into signal → SIGFPE
			// Program terminates
		// 
	} 
	catch(...)
	{
		cout<<"Number is 0";
	} // so a number is 0 and the error is system level not code level so the throw will not be done 
	*/
	/*
	globalNum/= number ; // Floating point exception (core dumped)
	You are dividing an int by zero.
	This causes:

		❌ Undefined Behavior
		❌ CPU raises arithmetic fault
		❌ OS sends SIGFPE
		❌ Program terminates
	*/
}

int main()
{
	cout<<"CERR vs COUT \n";

	int number =0 ;
	cout<<"----------BEfore call--------\n";
	cout<<"Number = " <<  number<<endl;
	cout<<"globalNum = " << globalNum <<endl;
	cout<<"----------------------------\n";
	try
	{
		function(number);
	}
	catch(const std::exception & r)
	{
		cout<<"[main] error : " << r.what() <<endl;
	}
	catch(...)
	{
		cout<<"[main] exception raised"<<endl;
	}
	cout<<"-------------After CAll---------\n";
	cout<<"Number = " <<  number<<endl;
	cout<<"globalNum = " << globalNum <<endl;
	cout<<"----------------------------\n";
}