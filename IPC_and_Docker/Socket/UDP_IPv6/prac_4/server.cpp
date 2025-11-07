#include <iostream>
#include <sys/socket.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <chrono>

using namespace std;

int main()
{
	cout<<"This is the program to understad the server side of UDP / IPv6 socket \n";
	int serverSocket =  socket(AF_INET6, SOCK_DGRAM, 0);
	sockaddr_in6 serverAddress;
	serverAddress.sin6_port = htons(8080);
	serverAddress.sin6_family = AF_INET6;
	serverAddress.sin6_addr = in6addr_any;

	bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress));

	listen(serverSocket, 10);

	char buffer[1024];

	socklen_t socker_len  = sizeof(serverAddress);
	recvfrom(serverSocket, buffer, sizeof(buffer), 0, (struct sockaddr *)&serverAddress, &socker_len );

	cout<<"Mess from cleint = " << buffer<<endl;
}