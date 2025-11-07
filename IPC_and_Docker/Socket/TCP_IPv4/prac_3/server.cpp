#include <iostream>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include "header.h"

using namespace std;

int main()
{
	cout<<"This is the program to understand the server side of the Socket \n";

	int serverSock = socket(AF_INET, SOCK_STREAM, 0);
	sockaddr_in serverAddress; 
	serverAddress.sin_port = htons(8080);
	serverAddress.sin_addr.s_addr = INADDR_ANY;
	serverAddress.sin_family = AF_INET;

	bind(serverSock, (struct sockaddr *)&serverAddress, sizeof(serverAddress));

	listen(serverSock, 10);

	int clientSock = accept(serverSock, nullptr, nullptr );

	// char buffer[1024];

	Data * ptr = new Data();
	recv(clientSock, ptr, sizeof(*ptr), 0);

	cout<< ptr->message<<endl;
	cout<< ptr->age<<endl;
	cout<< ptr->obj.salary<<endl;

	close(serverSock);
}