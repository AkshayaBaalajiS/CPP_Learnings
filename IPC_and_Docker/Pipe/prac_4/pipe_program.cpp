#include <cstring>
#include <iostream>
#include <chrono>
#include <sys/wait.h>

using namespace std;

int main()
{
	cout<<"This is the code to practise pipe program in C++ \n";

	int pipefd[2];
	if(pipe(pipefd)>0)
	{	
		cout<<"Pipe Not Created Successfully \n";
	}

	pid_t process_id ;
	process_id = fork();

	if(process_id >0)
	{
		close(pipefd[1]);
		char buffer[1024];
		read(pipefd[0], buffer, sizeof(buffer));
		cout<<"Mess from the pipe read end  : " << buffer <<endl;
		close(pipefd[0]);
	}
	else
	{
		close(pipefd[0]);
		char * buffer = "This is the mess from the server side ";
		write(pipefd[1], buffer, strlen(buffer));
		close(pipefd[1]);
	}
}