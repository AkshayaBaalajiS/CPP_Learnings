#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
using namespace std;

int main()
{
	cout<<"TCP based IPv4 socket client code \n";
	int clientDesc = socket(AF_INET, SOCK_STREAM, 0);
	sockaddr_in clientCode;
	clientCode.sin_port = htons(8080);
	clientCode.sin_family = AF_INET;
	clientCode.sin_addr.s_addr = inet_addr("127.0.0.1");

	connect(clientDesc, (struct sockaddr *)&clientCode, sizeof(clientCode));

	// char * buffer = "This is the message from the client ";
	char buffer[2024] ;
	strcpy(buffer, "This is the message from the client ");

	send(clientDesc, buffer, sizeof(buffer), 0);


}