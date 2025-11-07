#include <iostream>
#include <cstring>
// #include <pipe>
#include <sys/wait.h>

using namespace std;

int main()
{
	cout<<"This is the program to udnerstand the pipe working in C++\n";

	int pipeArray[2];	
	if(pipe(pipeArray) ==-1)
	{	
		cout<<"Pipe not created \n";
	}

	pid_t process_id;
	process_id = fork();
	if(process_id > 0) // parent  process id > 0
	{
		close(pipeArray[0]);
		char buffer[1024];
		strcpy(buffer, "Hi this is the message from the pipe index 1 and from parent  \n");
		write(pipeArray[1], buffer, sizeof(buffer));
		close(pipeArray[1]);
	}
	else // child process id = 0
	{
		close(pipeArray[1]);
		char buffer[1024];
		read(pipeArray[0], buffer, sizeof(buffer));
		cout<<"Message = " << buffer <<endl;
		close(pipeArray[0]);
	}
// in this program child receives the data 
}


// parent - process id > 0 
// child - process id =0

// write - [1]
// read - [0]