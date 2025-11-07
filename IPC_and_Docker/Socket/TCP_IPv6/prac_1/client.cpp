#include <iostream>
#include <chrono>
#include <sys/socket.h>
#include <sys/wait.h>
#include <cstring>
#include <arpa/inet.h>

using namespace std;

int main()
{
	cout<<"This is the code for the client where it uswes TCP bsaed IPv4 socket \n";

	int clientSocket = socket(AF_INET6, SOCK_STREAM, 0);
	sockaddr_in6 clientAddress;
	clientAddress.sin6_port = htons(8080);
	clientAddress.sin6_family = AF_INET6;
	inet_pton(AF_INET6, "::1" ,&clientAddress.sin6_addr);

	connect(clientSocket, (struct sockaddr *)&clientAddress, sizeof(clientAddress));

	char * Message  = "This is the message from the client \n";
	char buffer[1024];
	strcpy(buffer, static_cast<const char *>(Message));

	send(clientSocket, buffer, sizeof(buffer), 0);
}


/*
AF_INET + sockaddr_in (IPv4) ✅

or AF_INET6 + sockaddr_in6 (IPv6)
*/