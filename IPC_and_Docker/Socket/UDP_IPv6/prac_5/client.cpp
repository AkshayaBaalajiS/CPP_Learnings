#include <iostream>
#include <sys/socket.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <chrono>
#include <cstring>

using namespace std;

int main()
{
	cout<<"This is the client side program for UDP and IPv6 based socket programming \n";

	int clinetSocket = socket(AF_INET6, SOCK_DGRAM, 0);
	sockaddr_in6 clientAddress;
	clientAddress.sin6_port = htons(8080);
	clientAddress.sin6_family = AF_INET6;
	inet_pton(AF_INET6, "::1", &clientAddress.sin6_addr );


	char buffer[1024];
	strcpy(buffer, "message from client : How are you server ");

	sendto(clinetSocket, buffer, sizeof(buffer), 0, (struct sockaddr *)(&clientAddress), sizeof(clientAddress) );
	close(clinetSocket);
	
}