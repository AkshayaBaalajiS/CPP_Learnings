#include <iostream>
#include <cstring>
#include <chrono>
#include <sys/socket.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include "header.hpp"

using namespace std;

int main(int argc, char ** argv)
{
	cout<<"This is the program to understand client side of the socket \n";
	int clientSocket = socket(AF_INET6, SOCK_DGRAM, 0);
	sockaddr_in6 clientAddress;
	clientAddress.sin6_port = htons(8080);
	// clientAddress.sin6_addr.s_addr = inet_addr("127.0.0.1");
	 inet_pton(AF_INET6, "::1", &clientAddress.sin6_addr);  // loopback in IPv6	
	clientAddress.sin6_family = AF_INET6;

	connect(clientSocket, (struct sockaddr *)&clientAddress, sizeof(clientAddress));

	NameSpace::DataStructure obj;
	obj.change_value(12,'a',234.234f, 56756.234234, argv[1]);

	// send(clientSocket, &obj, sizeof(obj),0); // SEND IN udp 
	 sendto(clientSocket, &obj, sizeof(obj), 0, (struct sockaddr*)&clientAddress, sizeof(clientAddress));
}
