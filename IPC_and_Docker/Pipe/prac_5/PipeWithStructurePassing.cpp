#include <cstring>
#include <iostream>
#include <chrono>
#include <sys/wait.h>

using namespace std;

struct DataStructure
{
	int age;
	char * buffer;
	float salary[10];

	void operator = (float * arr)
	{
		for(int i=0;i<10;i++)
		{
			this->salary[i] = arr[i];
		}
	}
};	


struct DataStructure1
{
	int age;
	char  buffer[100];
	float salary[10];
	char * poiunter;	
};

int main()
{
	cout<<"This is the code to practise pipe program in C++ \n";

	int pipefd[2];
	if(pipe(pipefd)>0)
	{	
		cout<<"Pipe Not Created Successfully \n";
	}

	pid_t process_id ;
	process_id = fork();


	DataStructure1 * ptr ;
	DataStructure1  obj ;

	cout<<"Sizeof 1  " <<  sizeof(*ptr);
	cout<<"Sizeof 1  " <<  sizeof(obj);


	if(process_id >0)
	{
		close(pipefd[1]);
		DataStructure Objbuffer;
		DataStructure * buffer = &Objbuffer;
		read(pipefd[0], buffer, sizeof(*buffer));
		cout<<"----------------------------\n";
		cout<<"Mess from the pipe read end  \n";
		cout << buffer->age <<endl;
		cout << buffer->buffer <<endl;
		for(int i=0;i<10;i++)
		{
			cout<< buffer->salary[i] << ", ";
		}
		cout<<"\n----------------------------\n";
		close(pipefd[0]);
	}
	else
	{
		close(pipefd[0]);
		float salary [] ={12,23,34,54,56};
		DataStructure  buffer;
		buffer.age = 12;
		buffer = salary;
		buffer.buffer = "Akshaya Baalaji S ";
		DataStructure * input = &buffer;
		write(pipefd[1], input, sizeof(*input));
		close(pipefd[1]);
	}
}