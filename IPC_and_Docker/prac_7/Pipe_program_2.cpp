#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

struct A
{
	char * name ;
	int age;
	char * office_address;
	float salary;
};

int main()
{
	cout<<"Hi";
	A * newPtr = new A();

	A * newPtr_1 = new A();
	newPtr->age=23;
/*
	memory leak is below 
	first we are assigning a memory to pointer and later we are overwritting it with the read only string so seg fault raises ;
	newPtr->name=new char [100];
	newPtr->name="Akshaya Baalaji Senthilraj";
	newPtr->office_address = new char [100];
	newPtr->office_address ="Bhoruka Technology park Garudacharpalaya ";
*/	
	newPtr->salary=24500;
	char * name_2 ="Akshaya Baalaji Senthilraj";
	newPtr->name=name_2;

	char * addredd ="Bhoruka Technology park Garudacharpalaya ";
	// cout<<addredd<<endl;

	newPtr->office_address = addredd;

	// cout<<"----> "<<newPtr->office_address<<endl;

	int process_a[2];

	pid_t process;

	if(pipe(process_a)==-1)
	{
		cout<<"Error on Pipe Creation\n";
		exit(0);
	}
	process=fork();
	if(process>0)
	{
		close(process_a[0]);
		write(process_a[1], newPtr, sizeof(*newPtr));
		close(process_a[1]);

		wait(NULL);
	}
	else
	{
		close(process_a[1]);
		
		read(process_a[0], newPtr_1, sizeof(*newPtr));
		close(process_a[0]);

		cout<<newPtr_1->name<<" && " <<newPtr_1->age <<newPtr_1->office_address<<" && "<<endl; 
	
	}

	delete newPtr;
}