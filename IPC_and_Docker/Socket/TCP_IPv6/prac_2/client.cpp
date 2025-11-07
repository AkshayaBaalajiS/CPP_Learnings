#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstring>

using namespace std;

int main()
{
	cout<<"client : TCP based Ipv6 communication \n";

	int clientDesc = socket(AF_INET6, SOCK_STREAM, 0);

	sockaddr_in6 clientAdd;
	clientAdd.sin6_family = AF_INET6;
	clientAdd.sin6_port = htons(8080);
	inet_pton(AF_INET6, "::1", &clientAdd.sin6_addr);

	connect(clientDesc, (struct sockaddr *)&clientAdd, sizeof(clientAdd));

	char buffer[2056];
	strcpy(buffer, "This is the message from client side ; Hello Server \n");

	// socklen_t socket_lern = sizeof(clientAdd);// for UDP 
	send(clientDesc, buffer, sizeof(buffer), 0); // (struct sockaddr *)&clientAdd, (socket_lern));

}