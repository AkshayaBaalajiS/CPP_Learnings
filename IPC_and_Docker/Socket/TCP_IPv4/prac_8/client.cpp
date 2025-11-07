#include <iostream>
#include <chrono>
#include <sys/socket.h>
#include <sys/wait.h>
#include <cstring>
#include <arpa/inet.h>

using namespace std;

int main()
{
	cout<<"This is the code for the client where it uswes TCP bsaed IPv4 socket \n";

	int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	sockaddr_in clientAddress;
	clientAddress.sin_port = htons(8080);
	clientAddress.sin_family = AF_INET;
	clientAddress.sin_addr.s_addr = inet_addr("127.0.0.1");

	connect(clientSocket, (struct sockaddr *)&clientAddress, sizeof(clientAddress));

	char * Message  = "This is the message from the client \n";
	char buffer[1024];
	strcpy(buffer, static_cast<const char *>(Message));

	send(clientSocket, buffer, sizeof(buffer), 0);
}