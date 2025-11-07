#include <iostream>
#include <thread>
#include <chrono>
#include <sys/socket.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <cstring>
using namespace std;

int main()
{
	cout<<"This is the server code which used the UDP and IPv6 to communicate \n";
	int serverSocket = socket(AF_INET6, SOCK_DGRAM,0);
	sockaddr_in6 serverAddress;
	serverAddress.sin6_port = htons(8080);
	serverAddress.sin6_addr = in6addr_any;
	serverAddress.sin6_family = AF_INET6;

	bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress));

	listen(serverSocket,10);

	int clientSocket = accept(serverSocket, nullptr, nullptr );
	// std::this_thread::sleep_for(std::chrono::milliseconds(5000));

	char buffer[1024];
	socklen_t socketlen = sizeof(serverAddress);
	recvfrom(serverSocket, buffer, sizeof(buffer),0, (struct sockaddr * )&serverAddress, &socketlen);
	cout<<"Buffer = " << buffer<<endl;

	char replyBuffer[1024];
	strcpy(replyBuffer, "This is the message from the server side, the message received \n");
	sendto(serverSocket, replyBuffer, sizeof(replyBuffer), 0, (struct sockaddr *)&serverAddress, socketlen);
	
	close(serverSocket);
}