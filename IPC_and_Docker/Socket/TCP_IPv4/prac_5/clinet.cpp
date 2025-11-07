#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <sys/wait.h>
#include <thread>
#include <chrono>
#include <arpa/inet.h>
using namespace std;

int main()
{
	cout<<"This is the program to understand the clinet side of the socket programming \n";

	int clientSock = socket(AF_INET, SOCK_STREAM, 0);
	sockaddr_in clientAddress ;
	clientAddress.sin_port = htons(8080);
	clientAddress.sin_family=AF_INET;
	clientAddress.sin_addr.s_addr = inet_addr("127.0.0.1");



	char buffer[1202];
	strcpy(buffer, "This is the message from client side how are you \n");
	// cout<<"Sending  Buffer \n";

	char recvBuffe[1024];	
	connect(clientSock, (struct sockaddr *)(&clientAddress), sizeof(clientAddress));
	while(1)
	{
		send(clientSock, buffer, strlen(buffer), 0);
		// strlen -- is used to send only the message not the entire buffer 	
		// send(clientSock, buffer, sizeof(buffer), 0);	
		// std::this_thread::sleep_for(std::chrono::milliseconds(450));
		
		int sizeofBuff = recv(clientSock, recvBuffe, sizeof(recvBuffe)-1,0);
		if(sizeofBuff>0)
		{
			recvBuffe[sizeofBuff]='\0';
			cout<<"Message from server = " << recvBuffe<<endl;
		}
		else if (sizeofBuff == 0) {
            cout << "Server disconnected\n";
            break;
        } else {
            perror("recv failed");
            break;
        }
		std::this_thread::sleep_for(std::chrono::milliseconds(450));
	}

	close(clientSock);

}