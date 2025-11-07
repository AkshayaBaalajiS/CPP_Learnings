#include <iostream>
#include <unistd.h>

#include <sys/wait.h>
using namespace std;

#define MSG_SIZE 50 

int main()
{
	cout<<"This is the program to understand the Pipe way of IPC on CPP\n";

	char * data = "Hi All, This is the data \n";

	int pipe_ipc[2];

	if(pipe(pipe_ipc) == -1 )
	{
		std::cerr<<"Pipe creating error  : \n";
	}


	pid_t process_1 ;

	process_1 = fork();


	char * output_buffer = new char[1000];

	if(process_1 > 0)
	{
		// pipe_ipc[0] // 0 is for the reading end
		// pipe_ipc[1] // 1 is for the writing end
		
		close(pipe_ipc[0]); 
		write(pipe_ipc[1], data, MSG_SIZE);
		close(pipe_ipc[0]);

		wait(NULL);

	}

	else if(process_1 ==0 )
	{
		close(pipe_ipc[1]); 
		read(pipe_ipc[0],output_buffer, MSG_SIZE);
		close(pipe_ipc[0]);
		
		cout<<"OUtput = " << output_buffer<<endl;
	}
	else
	{
		cerr<<"Fork have not created any process \n";
	}




}