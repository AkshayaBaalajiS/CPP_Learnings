#include <iostream>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <thread>
#include <cstring>

using namespace std;

int main()
{
	cout<<"Server Side\n";	

	int serverDesc = socket(AF_INET, SOCK_STREAM, 0);

	sockaddr_in serverDetails ;
	serverDetails.sin_port = htons(8080);
	serverDetails.sin_family = AF_INET ;
	serverDetails.sin_addr.s_addr = INADDR_ANY ;

	bind(serverDesc, (struct sockaddr *)&serverDetails, sizeof(serverDetails));

	listen(serverDesc, 8);

	int clientDesc = accept(serverDesc, NULL,NULL);
	
	char buffer[10000];
	recv(clientDesc, buffer, sizeof(buffer),0);

	cout<<"The client sent : " << buffer <<endl;

	close(serverDesc);

}
