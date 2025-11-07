#include <iostream>
#include <sys/socket.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <chrono>
#include <thread>
#include "header.hpp"

using namespace std;

int main()
{
	cout<<"This is the program to understand the server side of the socket programming \n";
	int serverSocket = socket(AF_INET6, SOCK_DGRAM, 0);
	sockaddr_in6 serverAddress ;
	serverAddress.sin6_port = htons(8080);
	serverAddress.sin6_addr = in6addr_any;
	serverAddress.sin6_family = AF_INET6;

	bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress));

	listen(serverSocket,10);

	int clientSocket = accept(serverSocket, nullptr, nullptr);
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	NameSpace::DataStructure obj;
	// recv(clientSocket, &obj, sizeof(obj), 0); // this is for the IPv4 and TCP 
	socklen_t socklen = sizeof(serverAddress);
	recvfrom(serverSocket, &obj, sizeof(obj), 0, (struct sockaddr*)&serverAddress, &(socklen)); // IPV6 and UDP 

	obj.print_values(); 

	close(serverSocket);
}