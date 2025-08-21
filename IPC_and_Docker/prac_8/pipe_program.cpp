#include <iostream>
#include <sys/wait.h>
#include <thread>
#include <unistd.h>

using namespace std;

struct output
{
	char * name;
	int age;
	char * address;
	float * salary;
};


int main()
{
	cout<<"Pipe program \n";
	
	int pipe_array[2];
	pid_t process_id;

	if(pipe(pipe_array) == -1)
	{
		cerr<<"Pipe not created, Exiting \n";
		exit(0);
	}

	output * obj= new output() ;
	char * name_1 = "Akshaya Baalaji Senthilraj";
	int age_1 =23 ;
	char * address_1 = "Bhoruka Technology Park, Off outer ring rode, Near Garudacharpalaya Metro Station, Bangalore";
	float  salary_1[] = {0, 24500};
	
	obj->name  = name_1;
	obj->age = age_1;
	obj->address = address_1;
	obj->salary = salary_1;



	process_id = fork();
	if(process_id > 0 )
	{
		close(pipe_array[0]);
		write(pipe_array[1], obj, sizeof(*obj) );
		close(pipe_array[1]);
	}
	else if(process_id == 0 )
	{
		
		output * output_buff = new output();
		close(pipe_array[1]);
		read(pipe_array[0], output_buff, sizeof(*obj) );
		close(pipe_array[0]);

		cout<<"______________________________________________________\n";
		cout<<"Name = " << output_buff->name<<endl;
		cout<<"age = " << output_buff->age<<endl;
		cout<<"address = " << output_buff->address<<endl;
		cout<<"salary = " << output_buff->salary[0] << "  "  << output_buff->salary[1] <<endl;
		cout<<"______________________________________________________\n";

		wait(NULL);
	}
	else
	{
		cerr<<"Pipe not created properly\n";
	}


	

}