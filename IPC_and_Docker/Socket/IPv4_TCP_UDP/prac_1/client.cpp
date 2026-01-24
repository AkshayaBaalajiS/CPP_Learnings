#include <iostream>
#include "header.hpp"
#include <arpa/inet.h>

using namespace std;

int main()
{
	#ifdef TCP
	cout<<"Client side of socket TCP  \n";
	#else
	cout<<"Client side of socket  UDP \n";
	#endif	

	#ifdef TCP
	int clientDes = socket(AF_INET, SOCK_STREAM, 0);
	#else 
	int clientDes = socket(AF_INET, SOCK_DGRAM, 0);
	#endif

	sockaddr_in clientDet ;
	clientDet.sin_port = htons(8080);
	clientDet.sin_addr.s_addr = inet_addr("127.0.0.1");
	clientDet.sin_family = AF_INET ;
	
	connect(clientDes, (sockaddr *)(&clientDet), sizeof(clientDet));

	int * ptr = new int[100];
	
	
	Structure * Obj = new Structure();
	(*Obj).arr[0] = 12;
	(*Obj).arr[1] = 23;
	(*Obj).arr[2] = 34;
	(*Obj).arr[3] = 45;
	(*Obj).arr[4] = 56;
	(*Obj).arr[5] = 67;
	(*Obj).arr[6] = 78;
	(*Obj).arr[7] = 89;

	#ifdef TCP
	send(clientDes, Obj , sizeof(*Obj),0);
	#else
	socklen_t clientSize  = sizeof(clientDet);
	sendto(clientDes, Obj , sizeof(*Obj),0, (sockaddr *)(&clientDet), clientSize);
	#endif	


}