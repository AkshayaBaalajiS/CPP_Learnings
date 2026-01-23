#include <iostream>
#include <arpa/inet.h>
#include <sys/wait.h>
#include "header.hpp"

using namespace std;

int main()
{
	#ifdef TCP
	cout<<"Socket IPv4 TCP  \n";
	#else
	cout<<"Socket IPv4 UDP \n";
	#endif

	#ifdef TCP
	int serverDesc = socket(AF_INET, SOCK_STREAM, 0);
	#else
	int serverDesc = socket(AF_INET, SOCK_DGRAM, 0);
	#endif
	
	sockaddr_in serverDet;
	serverDet.sin_port = htons(8080);
	serverDet.sin_addr.s_addr = INADDR_ANY;
	serverDet.sin_family = AF_INET;

	bind(serverDesc, (sockaddr *)(&serverDet), sizeof(serverDet));

	listen(serverDesc, 10);

	#ifdef TCP
	int clientDes = accept(serverDesc, nullptr, nullptr);
	#endif


	void * ptr = (void *)sizeof(1000);
	int arr[23];

	Structure * Obj = new Structure();

	#ifdef TCP
	recv(clientDes,Obj, sizeof(*Obj),0);
	#else
	socklen_t clientSize = sizeof(serverDet);
	recvfrom(serverDesc,Obj, sizeof(*Obj), 0, (struct sockaddr  *)(&serverDet),&clientSize);
	#endif

	cout<<"Data ----------------------\n";
	cout<<(*Obj).arr[0] << " " <<(*Obj).arr[1] << " " <<(*Obj).arr[2] << " " <<(*Obj).arr[3] << " " <<(*Obj).arr[4] << " " <<(*Obj).arr[5] << " " <<(*Obj).arr[6] << " " <<(*Obj).arr[7] << endl;// 
	cout<<"----------------------------\n";

	close(serverDesc);
}