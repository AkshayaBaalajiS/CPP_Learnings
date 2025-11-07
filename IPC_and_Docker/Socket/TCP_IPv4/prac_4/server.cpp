#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <chrono>
#include <thread>
using namespace std;

int main()
{
	cout<<"This is the program to understand the server part of the TCP communication through socket \n";

	int serverSock = socket(AF_INET, SOCK_STREAM, 0);
	sockaddr_in serverAddress ;
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(8080);
	serverAddress.sin_addr.s_addr= INADDR_ANY ;

	bind(serverSock, (struct sockaddr *)&serverAddress, sizeof(serverAddress));

	listen(serverSock, 10);

	int clinetSock = accept(serverSock, nullptr, nullptr);
	/*
		int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
sockfd: the listening socket

addr: pointer to a buffer where the client’s address (IP + port) will be stored

addrlen: pointer to the size of that buffer (input/output)
		*/

	cout<<"Server Side for replying message \n";
	while(1)
	{

		
		char buffer[1024];
		int bytesreceived = recv(clinetSock, buffer, sizeof(buffer),0);
		if(bytesreceived>0)
		{
			buffer[bytesreceived]='\n';
		}
		cout<<"Buffer = " <<  buffer <<endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(450));

	}
	close(serverSock); 	


}