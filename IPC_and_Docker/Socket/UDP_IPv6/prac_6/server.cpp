#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>

using namespace std;

int main()
{
	cout<<"server code : UDP based IPv6 communication \n";

	int serverDesc = socket(AF_INET6, SOCK_DGRAM, 0);

	sockaddr_in6 serverDet;
	serverDet.sin6_family = AF_INET6;
	serverDet.sin6_port = htons(8080);
	serverDet.sin6_addr = in6addr_any;

	bind(serverDesc, (struct sockaddr *)&serverDet,sizeof(serverDet));

	listen(serverDesc, 10);

	char  buffer[2056] ;

	socklen_t socket_length = sizeof(serverDet);
	recvfrom(serverDesc, buffer, sizeof(buffer), 0, (struct sockaddr *)&serverDet, &socket_length);

	cout<<"Data received from client  : " << buffer << std::endl;
}