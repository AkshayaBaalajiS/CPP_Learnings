#include <iostream>
#include <sys/wait.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <thread>
#include <cstring>



using namespace std;

int main()
{
	cout<<"Client code \n";

	int clientDesc = socket(AF_INET, SOCK_STREAM, 0);

	sockaddr_in clientDetails ;
	clientDetails.sin_family = AF_INET;
	clientDetails.sin_port = htons(8080);
	clientDetails.sin_addr.s_addr = inet_addr("127.0.0.1");

	connect(clientDesc, (struct sockaddr *)&clientDetails, sizeof(clientDetails));

	char * message  = "Hi Bye Server I am familiar with socker now\n";

	send(clientDesc, message, strlen(message), 0);

	close(clientDesc);

}