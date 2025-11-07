#include <iostream>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>
// #include <arpa/inet.h>   // inet_addr
using namespace std;

int main()
{
	cout<<"This is the client code for Socker side programming \n";

	int clientSocker = socket(AF_INET, SOCK_STREAM, 0);
	//protocol 0 

	sockaddr_in clientAddress;
	clientAddress.sin_port = htons(8080);
	clientAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
	clientAddress.sin_family = AF_INET;

	connect(clientSocker, (struct sockaddr *)&clientAddress, sizeof(clientAddress));

	char message[] = "Hi server this message is from client side \nHow are you \n";

	send(clientSocker, message, sizeof(message),0);

	close(clientSocker);
}