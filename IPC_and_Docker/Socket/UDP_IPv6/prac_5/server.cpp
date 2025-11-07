#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <sys/wait.h>
#include <arpa/inet.h>

using namespace std;

int main()
{
	cout<<"This is the program to understand the server side of UDP and IPv6 based socket communication \n";

	int serverSocket = socket(AF_INET6, SOCK_DGRAM, 0);
	sockaddr_in6 serverAddress;
	serverAddress.sin6_port = htons(8080);
	serverAddress.sin6_family = AF_INET6;
	serverAddress.sin6_addr = in6addr_any;

	bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress));

	char buffer[1024];
	socklen_t socklen_var = sizeof(serverAddress);
	recvfrom(serverSocket, buffer, sizeof(buffer), 0, (struct sockaddr *)&serverAddress, &socklen_var );
	cout<<"Message = "<<buffer<<endl;
}
