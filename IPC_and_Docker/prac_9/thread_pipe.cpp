#include <iostream>
#include <thread>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;


struct Details 
{
	int age;
	char * name ;
	char * address ;
	float * salary ;
};

int pipe_Arr[2];

Details * input = new Details();
Details * output = new Details();


void * input_buffer(void * arg)
{
	close(pipe_Arr[0]);
	write(pipe_Arr[1], input, sizeof(*input));
	close(pipe_Arr[1]);

	std::this_thread::sleep_for(std::chrono::milliseconds(500));

	return NULL;
}

void * output_buffer(void * arg)
{

	std::this_thread::sleep_for(std::chrono::milliseconds(80));
	close(pipe_Arr[1]);
	read(pipe_Arr[0], output, sizeof(*input));
	close(pipe_Arr[0]);

	cout<<"Output ----------\n";
	cout<<"Name  = " << output->name <<endl;
	cout<<"address  = " << output->address <<endl;
	cout<<"salary  = " << output->salary[0] << " &  " << output->salary[1] << endl;

	std::this_thread::sleep_for(std::chrono::milliseconds(780));
	return NULL;
}


int main()
{
	cout<<"Process and Pipe program \n";
	pthread_t process_1, process_2;

	if(pipe(pipe_Arr)==-1)
	{
		cout<<"Process not created \n";
		exit(1);
	}

	char name [] = "Akshaya Baalaji Senthilraj";
	char addr[] = "Bhoruka Tech Park Garudacharpalaya ";
	float sal[] = {0, 24500};
	
	input->age=23;
	input->name = name;
	input->salary=sal;
	input->address =addr;

	
	pthread_create(&process_1, NULL, input_buffer, NULL);
	pthread_create(&process_2, NULL, output_buffer, NULL);
	
	pthread_join(process_1, NULL);
	pthread_join(process_2, NULL);
	
	

	cout<<"--------end---------\n";


}