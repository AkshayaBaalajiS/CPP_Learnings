#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <thread>
#include <cstring>
#include <netinet/in.h>
#include <arpa/inet.h>   // inet_addr


using namespace std;

int main()
{
	cout<<"Client Code \n";

	int clientDescriptor = socket(AF_INET, SOCK_STREAM, 0);
	
	sockaddr_in clientDetails ;
	clientDetails.sin_family = AF_INET;
	clientDetails.sin_port = htons(8080);
	clientDetails.sin_addr.s_addr = inet_addr("127.0.0.1");

	connect(clientDescriptor, (struct sockaddr *)&clientDetails, sizeof(clientDetails));

	char * message  = "Hi Bye Server Will deep dive in it ";
	send( clientDescriptor, message, strlen(message), 0 );

	close(clientDescriptor);



}