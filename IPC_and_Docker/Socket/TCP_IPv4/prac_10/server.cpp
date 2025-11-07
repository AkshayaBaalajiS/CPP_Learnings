#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>


using namespace std;
int main()
{
	cout<<"TCP based IPv4 socket server code\n";
	int serverDesc = socket(AF_INET, SOCK_STREAM, 0);

	sockaddr_in serverAdd;
	serverAdd.sin_port = htons(8080);
	serverAdd.sin_addr.s_addr = INADDR_ANY;
	serverAdd.sin_family = AF_INET;

	bind(serverDesc, (struct sockaddr *)&serverAdd, sizeof(serverAdd));

	listen(serverDesc, 10);

	int clientDes = accept(serverDesc,  nullptr, nullptr);
	char buffer[2024];
	recv(clientDes, buffer, sizeof(buffer), 0);

	cout<<"Data = 	" << buffer <<std::endl;

}