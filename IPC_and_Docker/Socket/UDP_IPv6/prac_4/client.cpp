#include <iostream>
#include <cstring>
#include <chrono>
#include <sys/socket.h>
#include <sys/wait.h>
#include <arpa/inet.h>

using namespace std;

int main()
{
	cout<<"This is the program to understand the clinet side of UDP and IPv6 socket \n";

	int clientSocket = socket(AF_INET6, SOCK_DGRAM, 0);
	sockaddr_in6 clientAddress;
	clientAddress.sin6_port = htons(8080);
	inet_pton(AF_INET6, "::1", &clientAddress.sin6_addr);
	clientAddress.sin6_family = AF_INET6;

	connect(clientSocket, (struct sockaddr *)(&clientAddress),sizeof(clientAddress) );

	char buffer[1024];
	strcpy(buffer,"Akshaya Baalaji S ");

	sendto(clientSocket, buffer, sizeof(buffer),0, (struct sockaddr *)(&clientAddress),sizeof(clientAddress) );
}
