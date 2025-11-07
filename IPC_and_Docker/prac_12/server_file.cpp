#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <thread>
#include <cstring>
#include <netinet/in.h>

using namespace std;

int main()
{
	cout<<"Server program \n";

	int serverDescriptor = socket(AF_INET, SOCK_STREAM, 0);
	// 0 protocol number OS picks the correct number for protocol 

	sockaddr_in serverDetails ;
	serverDetails.sin_family = AF_INET;
	serverDetails.sin_port = htons(8080);
	serverDetails.sin_addr.s_addr = INADDR_ANY;

	bind(serverDescriptor, (struct sockaddr *)&serverDetails, sizeof(serverDetails));

	listen(serverDescriptor, 5);

	int clientDescriptor = accept(serverDescriptor, nullptr, nullptr );

	char buffer[1000];
	recv(clientDescriptor, buffer, sizeof(buffer), 0);

	cout<<"The Message  :  " << buffer <<endl;

	close(serverDescriptor);

}
