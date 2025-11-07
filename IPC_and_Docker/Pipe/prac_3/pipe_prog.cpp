#include <iostream>
#include <chrono>
#include <cstring>
#include <sys/socket.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include "header.hpp"

using namespace std;

int main()
{
	cout<<"This is the server code for receiving the data from the client \n";

	int pipefd[2];

	if(pipe(pipefd)>0)
	{
		cout<<"pipe created successfully\n";
	}
	
	pid_t process;
	process = fork();

	if(process>0)
	{
		close(pipefd[0]);
		char buffer[1000];
		char * ptr = "This is the message from the parent pipe, how are you client \n";
		strcpy(buffer, static_cast<const char *>(ptr));
		write(pipefd[1], buffer, sizeof(buffer));
		close(pipefd[1]);
		// char replyBuffer[1024];
		// read(pipefd[0], buffer, sizeof(buffer));
		// cout<<"Message from the client  = " << buffer<<endl;
		// close(pipefd[0]);

	}
	else
	{
		close(pipefd[1]);
		char buffer[1000];
		read(pipefd[0], buffer, sizeof(buffer));
		cout<<"Message from the server  = " << buffer<<endl;
		// char replyBuffer[1024];
		// strcpy(replyBuffer, "This is a acknowledgement message from client");
		// close(pipefd[0]);
		// write(pipefd[1], replyBuffer, sizeof(replyBuffer));
		close(pipefd[1]);
	}

}

// 1 -  write 
// 0 - read 


// commented lines are the proof that the pipe wont allow 2 way communication 