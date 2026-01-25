#include "header.hpp"
#include <arpa/inet.h>
// #include <sys/wait.h> // only if we are using the wait 
using namespace std;
int main()
{
	#ifdef TCP
	cout<<"Server code of TCP\n";
	#else
	cout<<"Server code of UDP\n";
	#endif
	
	#ifdef TCP
	int serverDesc = socket(AF_INET, SOCK_STREAM, 0);
	#else
	int serverDesc = socket(AF_INET, SOCK_DGRAM, 0);
	#endif

	sockaddr_in serverADd;
	serverADd.sin_port = htons(8080);
	serverADd.sin_family = AF_INET;
	serverADd.sin_addr.s_addr = INADDR_ANY;

	bind(serverDesc, (struct sockaddr *)&serverADd, sizeof(serverADd));

	#ifdef TCP 
	listen(serverDesc, 10);
	int clientDes = accept(serverDesc, nullptr, nullptr);
	#endif

	Structure * ptr = new Structure();
	#ifdef TCP 
	recv(clientDes, ptr, sizeof(*ptr),0);
	#else
	socklen_t socklene= sizeof(serverADd);
	recvfrom(serverDesc, ptr, sizeof(*ptr), 0,(struct sockaddr *)&serverADd,&socklene);
	#endif

	cout<<*ptr;

}