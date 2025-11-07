#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>

using namespace std;

int main()
{
	cout<<"server code : TCP based IPv6 communication \n";

	int serverDesc = socket(AF_INET6, SOCK_STREAM, 0);

	sockaddr_in6 serverDet;
	serverDet.sin6_family = AF_INET6;
	serverDet.sin6_port = htons(8080);
	serverDet.sin6_addr = in6addr_any;

	bind(serverDesc, (struct sockaddr *)&serverDet,sizeof(serverDet));

	listen(serverDesc, 10);

	int clientDesc = accept(serverDesc, nullptr, nullptr);
	char  buffer[2056] ;

	// socklen_t socket_length = sizeof(serverDet);
	recv(clientDesc, buffer, sizeof(buffer), 0);//, (struct sockaddr *)&serverDet, &socket_length);

	cout<<"Data received from client  : " << buffer << std::endl;
}