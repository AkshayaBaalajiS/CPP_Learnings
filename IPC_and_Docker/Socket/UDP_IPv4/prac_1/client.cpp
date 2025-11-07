#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstring>

using namespace std;

int main()
{
	cout<<"client : UDP based Ipv4 communication \n";

	int clientDesc = socket(AF_INET, SOCK_DGRAM, 0);

	sockaddr_in clientAdd;
	clientAdd.sin_family = AF_INET;
	clientAdd.sin_port = htons(8080);
	clientAdd.sin_addr.s_addr = inet_addr("127.0.0.1");

	connect(clientDesc, (struct sockaddr *)&clientAdd, sizeof(clientAdd));

	char buffer[2056];
	strcpy(buffer, "This is the message from client side ; Hello Server \n");

	socklen_t socket_lern = sizeof(clientAdd);
	sendto(clientDesc, buffer, sizeof(buffer), 0, (struct sockaddr *)&clientAdd, (socket_lern));

}