#include <iostream>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <thread>
#include <cstring>

using namespace std;

int main()
{
	cout<<"Client code \n";

	int clientDesc = socket(AF_INET, SOCK_STREAM, 0);

	sockaddr_in clientDetails;
	clientDetails.sin_family  = AF_INET;
	clientDetails.sin_port = htons(8080);
	clientDetails.sin_addr.s_addr = inet_addr("127.0.0.1");

	// mistake done here : bid should be on the server side 
	
	connect(clientDesc ,(struct sockaddr *)&clientDetails, sizeof(clientDetails));

	char * message = "Hi Bye Server I will Deep Dive in it \n";
	send(clientDesc, message, strlen(message), 0 );

	close(clientDesc);


}