#include <iostream>
#include <chrono>
#include <sys/socket.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <thread>

using namespace std;

int main()
{
	cout<<"This is the server code where it used the TCP and IPv4 socket \n";

	int serverSocket  = socket(AF_INET6, SOCK_STREAM, 0);
	sockaddr_in6 serverAddress;
	serverAddress.sin6_port = htons(8080);
	serverAddress.sin6_family = AF_INET6;
	serverAddress.sin6_addr = in6addr_any ;

	bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress));

	listen(serverSocket, 10);

	int clientSocket  = accept(serverSocket, nullptr, nullptr);

	char buffer[1024];
	//recv(clientSocket, buffer, sizeof(buffer),0);
	recv(clientSocket, buffer, sizeof(buffer),0); 
	cout<<"Message = " << buffer <<endl;
}


/*
AF_INET + sockaddr_in (IPv4) ✅

or AF_INET6 + sockaddr_in6 (IPv6)
*/