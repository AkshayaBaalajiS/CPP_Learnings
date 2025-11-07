#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/wait.h>

using namespace std;

int main()
{
	cout<<"This is the code where server communicate with client through UDP and IPv6\n";
	int serverSocket = socket(AF_INET6, SOCK_DGRAM, 0);
	sockaddr_in6 serverAddress;
	serverAddress.sin6_port = htons(8080);
	serverAddress.sin6_addr = in6addr_any;
	serverAddress.sin6_family = AF_INET6;

	bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));

	listen(serverSocket,10);

	int clientSocket = accept(serverSocket, nullptr, nullptr);
	socklen_t socketlen = sizeof(serverAddress);
	
	char buffer[1024];
	recvfrom(serverSocket, buffer, sizeof(buffer),0, (struct sockaddr *)(&serverAddress), &socketlen );
	cout<<"Received from : " << buffer<<endl;
}