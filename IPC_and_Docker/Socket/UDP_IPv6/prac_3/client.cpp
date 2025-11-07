#include <iostream>
#include <thread>
#include <sys/socket.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <cstring>

using namespace std;

int main()
{
	cout<<"This is the client side of the socket UDP and IPv4\n";
	int clientSock = socket(AF_INET6, SOCK_DGRAM, 0);
	sockaddr_in6 clientAddress;
	clientAddress.sin6_port = htons(8080);
	clientAddress.sin6_family = AF_INET6;
	inet_pton(AF_INET6,"::1", &clientAddress.sin6_addr);

	connect(clientSock, (struct sockaddr *)&clientAddress, sizeof(clientAddress));

	char buffer[1024];
	strcpy(buffer,"This the message from client, How are you server");

	sendto(clientSock, buffer, sizeof(buffer), 0, (struct sockaddr *)&clientAddress, sizeof(clientAddress));
}