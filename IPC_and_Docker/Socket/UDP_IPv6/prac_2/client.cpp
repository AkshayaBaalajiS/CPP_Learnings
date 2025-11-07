#include <iostream>
#include <chrono>
#include <sys/socket.h>
#include <sys/wait.h>
#include <thread>
#include <cstring>
#include <arpa/inet.h>

using namespace std;

int main()
{
	cout<<"This is the client code to send the data through the TCP and IPv6 communication \n";
	int clientSocket = socket(AF_INET6, SOCK_DGRAM, 0);
	sockaddr_in6 clientAddress ;
	clientAddress.sin6_port = htons(8080);
	clientAddress.sin6_family = AF_INET6;
	// clientAddress.sin6_addr = inet6_addr("127.0.0.1");
	inet_pton(AF_INET6, "::1", &clientAddress.sin6_addr);  // loopback in IPv6	


	connect(clientSocket, (struct sockaddr *)&clientAddress,sizeof(clientAddress));

	char buffer[1024];
	strcpy(buffer, "This is the message from client, How are the you server ? ");

	socklen_t socketlen = sizeof(clientAddress);
	sendto(clientSocket, buffer, sizeof(buffer),0, (struct sockaddr *)&clientAddress, socketlen);


	char Replybuffer[1024];
	recvfrom(clientSocket, Replybuffer, sizeof(Replybuffer), 0, (struct sockaddr *)&clientAddress, &socketlen);
	cout<<"Reply buffer = " << Replybuffer<<endl;
	close(clientSocket);
}