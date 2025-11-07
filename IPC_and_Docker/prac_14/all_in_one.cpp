#include <iostream>
#include <thread>
#include <chrono>
#include <cstring>
#include <sys/wait.h>
#include <sys/socket.h>
#include <arpa/inet.h>

using namespace std;


void * function_1 (void * arg)
{
	for(int i=0;i<20;i++)
	{
		auto start_time = std::chrono::high_resolution_clock::now();	
		std::this_thread::sleep_for(std::chrono::milliseconds(501));
		auto end_time = std::chrono::high_resolution_clock::now();
		auto total_time  = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time);
		cout<<"Iteration "<<i <<" took " << total_time.count() << " milliseconds \n";
	}
	return NULL;
}

void * function_2 (void * arg)
{
	for(int i=0;i<20;i++)
	{
		auto start_time = std::chrono::high_resolution_clock::now();	
		std::this_thread::sleep_for(std::chrono::milliseconds(201));
		auto end_time = std::chrono::high_resolution_clock::now();
		auto total_time  = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time);
		cout<<"Iteration "<<i <<" took " << total_time.count() << " milliseconds \n";
	}
	return NULL;
}

void thread_creation(pthread_t thread_1, pthread_t thread_2)
{
	cout<<"Threading starts \n";

	pthread_create(&thread_1, NULL, function_1, NULL);
	pthread_create(&thread_2, NULL, function_2, NULL);

	pthread_join(thread_1, NULL);
	pthread_join(thread_2, NULL);
}

struct SampleStructure 
{
	char name[100];
	char address[100];
	int age ;
};

void pipe()
{
	pid_t process_id;

	int pipefd[2]; // for write and read 

	if(pipe(pipefd) ==-1)
	{
		cout<<"Error on Pipe \n";
	}

	process_id = fork();

	if(process_id > 0)
	{
		SampleStructure  input ;
		strcpy(input.name, "Akshaya Baalaji S");
		strcpy(input.address, "Bhoruka Tech Park Garudacharpalaya metro");
		input.age = 123;
		write(pipefd[1], &input, sizeof(input));
		close(pipefd[1]);
	}
	else
	{
		SampleStructure output;

		close(pipefd[1]);
		read(pipefd[0], &output, sizeof(output));
		close(pipefd[0]);

		cout<<"Name   = " << output.name<<endl;
		cout<<"Address   = " << output.address<<endl;
		cout<<"Age   = " << output.age<<endl;
	}

}

void socket()
{
	int serverDesc = socket(AF_INET, SOCK_STREAM, 0);

	sockaddr_in serverDetails ;
	serverDetails.sin_family = AF_INET;
	serverDetails.sin_port = htons(8080);
	serverDetails.sin_addr.s_addr = INADDR_ANY;

	bind(serverDesc, (struct sockaddr *)(&serverDetails), sizeof(serverDetails));

	listen(serverDesc, 10);

	int clientDesc =  accept(serverDesc, NULL, NULL);
	char buffer[1000];
	recv(clientDesc, buffer, sizeof(buffer), 0);

	cout<<"Message  = " << buffer<<endl;
}

void choose(int args, pthread_t thread_1 = 0, pthread_t thread_2 =0 )
{
	switch(args)
	{
		case 1:
			cout<<"You have choosen Threading\n";
			thread_creation(thread_1, thread_2);
			break;
		case 2:
			cout<<"You have choosen Pipe \n";
			pipe();
			break;
		case 3:
			cout<<"You have choosen Socket \n";
			socket();
			break;
		default:
			cout<<"Enter correctly\n";
			break;
	}
}
int main(int argc , char ** args)
{
	cout<<"Choose one from below \n";
	cout<<"1. Threading\n2.Pipe\n3.Socker\n";


	// if(strcmp(args[1],"") == 0 ) // implementation is wrong 
	
	pthread_t thread_1; 
	pthread_t thread_2;

	if( argc < 2 )
	{
		int input;
		cout<<"Enter the number \n";
		cin>>input;

		choose(input);
	}
	else
	{
		int number = stoi(args[1]);
		choose(number);
	}

}	