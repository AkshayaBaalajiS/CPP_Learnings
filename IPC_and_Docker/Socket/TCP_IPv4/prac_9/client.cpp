#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>


using namespace std;

int main()
{
	cout<<"Client.cpp code \n";

	int clientDesc = socket(AF_INET, SOCK_STREAM, 0);

	sockaddr_in clientDet;
	clientDet.sin_port = htons(8080);
	clientDet.sin_addr.s_addr = inet_addr("127.0.0.1");
	clientDet.sin_family = AF_INET;

	connect(clientDesc, (struct sockaddr *)&clientDet, sizeof(clientDet));

	char buffer[1000] = "Akshaya Baalaji Sending message throufh the buffer from client \n";

	send(clientDesc, buffer, sizeof(buffer),0);
}