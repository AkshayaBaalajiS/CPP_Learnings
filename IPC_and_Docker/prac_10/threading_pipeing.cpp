#include<iostream>
#include <thread>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

void * function_1(void *)
{
	for(int i=0;i<20;i++)
	{
		auto start_time = std::chrono::high_resolution_clock::now();

		std::this_thread::sleep_for(std::chrono::milliseconds(507));

		auto end_time = std::chrono::high_resolution_clock::now();
		auto total_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time);

		cout<<"Function 1 took "<< total_time.count() <<"Sec for "<< i << " iteration \n";
		
	}
	return NULL;

}

void * function_2(void *)
{
	for(int i=0;i<20;i++)
	{
		auto start_time = std::chrono::high_resolution_clock::now();

		std::this_thread::sleep_for(std::chrono::milliseconds(207));

		auto end_time = std::chrono::high_resolution_clock::now();
		auto total_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time);

		cout<<"Function 2 took "<< total_time.count() <<"Sec for "<< i << " iteration \n";
		
	}
	return NULL;

}

struct transfer
{
	char * name;
	char * address;
	double  salary[2];
	int age;
};


int pipefd[2];				
transfer output;

class threading_class
{
	public :
		pthread_t thread_1, thread_2;
		pid_t process_id;

		transfer input ;	

		void thread_start()
		{
			cout<<"Create thread\n";
			pthread_create(&thread_1, NULL, function_1, NULL);
			pthread_create(&thread_2, NULL, function_2, NULL);
			pthread_join(thread_1,NULL);
			pthread_join(thread_2,NULL);
			return ;	
		}
		
		void pipeing()
		{
			char * name = "Akshaya Baalaji \n";
			input.name=name;
			char * address = "Bhoruka Tech Park Garudacharpalaya \n";
			input.address=address;
			input.age = 23;
			static double sal[] = {0,24500};
			// double * sall = sal;
			input.salary[0]=sal[0];
			input.salary[1]=sal[1];


			if(pipe(pipefd)==-1)
			{
				cout<<"pipe failed \n";
				exit(0);
			}

			process_id=fork();
			if(process_id>0)
			{
				close(pipefd[0]);
				write(pipefd[1], &input,sizeof(input));
				close(pipefd[1]);
				wait(NULL);
			}
			else if(process_id==0)
			{
				close(pipefd[1]);
				read(pipefd[0], &output, sizeof(input));
				close(pipefd[0]);
				wait(NULL);
			}
			else
			{
				cout<<"Something goes wrong \n";
			}
		}
};

int main(int argc, char ** args)
{
	cout<<"Enter options based on your choice \n";
	cout<<"1.Threading \n2.Pipeing\n";
	cout<<*args[1] << " is clicked ";
	threading_class * threadPtr = new threading_class();
	cout<<*args[1] <<"____\n";
	switch(*args[1])
	{
		case '1':
			threadPtr->thread_start();
			break;
		case '2':
			threadPtr->pipeing();
			cout<<output.name << "  " << output.address << " " << output.age << " " << output.salary[1] <<endl;
			break;

		default:
			cout<<"Enter the option correctly \n";		
			break;
	}

}
