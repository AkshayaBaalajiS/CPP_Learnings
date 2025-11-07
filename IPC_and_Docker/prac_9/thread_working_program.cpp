#include <iostream>
#include <thread>
#include <unistd.h>
#include <cstring>
#include <sys/wait.h>

using namespace std;

struct Details 
{
	int age;
	char name[100];
	char address[100];
	float salary[2];
};

int pipe_Arr[2];

Details input;
Details output;

void * input_buffer(void * arg)
{
	close(pipe_Arr[0]);
	write(pipe_Arr[1], &input, sizeof(input));
	close(pipe_Arr[1]);
	return NULL;
}

void * output_buffer(void * arg)
{
	close(pipe_Arr[1]);
	read(pipe_Arr[0], &output, sizeof(output));
	close(pipe_Arr[0]);

	cout<<"Output ----------\n";
	cout<<"Name    = " << output.name <<endl;
	cout<<"Address = " << output.address <<endl;
	cout<<"Salary  = " << output.salary[0] << " &  " << output.salary[1] << endl;

	return NULL;
}

int main()
{
	cout<<"Process and Pipe program \n";
	pthread_t process_1, process_2;

	if(pipe(pipe_Arr)==-1)
	{
		cout<<"Pipe creation failed\n";
		exit(1);
	}

	// Initialize input
	input.age = 23;
	strcpy(input.name, "Akshaya Baalaji Senthilraj");
	strcpy(input.address, "Bhoruka Tech Park Garudacharpalaya");
	input.salary[0] = 0;
	input.salary[1] = 24500;

	pthread_create(&process_1, NULL, input_buffer, NULL);
	pthread_create(&process_2, NULL, output_buffer, NULL);

	pthread_join(process_1, NULL);
	pthread_join(process_2, NULL);

	cout<<"--------end---------\n";
}
