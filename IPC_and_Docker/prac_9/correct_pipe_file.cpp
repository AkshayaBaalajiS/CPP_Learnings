#include <iostream>
#include <thread>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;


struct Details 
{
	int age;
	char * name ;
	char * address ;
	float * salary ;
};

int main()
{
	cout<<"Process and Pipe program \n";
	pid_t process ;
	int array[2];

	if(pipe(array)==-1)
	{
		cout<<"Process not created \n";
		exit(1);
	}

	char name [] = "Akshaya Baalaji Senthilraj";
	char addr[] = "Bhoruka Tech Park Garudacharpalaya ";
	float sal[] = {0, 24500};
	
	Details * input = new Details();
	input->age=23;
	input->name = name;
	input->salary=sal;
	input->address =addr;
	Details * output = new Details();
	
	process = fork();
	

	if(process>0)
	{
		close(array[0]);
		write(array[1], input, sizeof(*input));
		close(array[1]);
	}
	else if(process ==0)
	{
		close(array[1]);
		read(array[0], output, sizeof(*input));
		close(array[0]);

		cout<<"Output ----------\n";
		cout<<"Name  = " << output->name <<endl;
		cout<<"address  = " << output->address <<endl;
		cout<<"salary  = " << output->salary[0] << " &  " << output->salary[1] << endl;

		wait(NULL);
	}
	else
	{
		cout<<"Fault \n";
	} 

	cout<<"--------end---------\n";


}