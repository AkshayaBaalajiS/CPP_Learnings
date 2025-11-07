#include <iostream>
#include <cstring> // for strcpy
#include <sys/wait.h> // for pipe, fork 

using namespace std;

struct dataStructure
{
	int intdata;
	char charData;
	char charPointer[200];
	float floatPointer[5];
};


int main()
{
	cout<<"This is the program to understand pipe working in CPP\n";
	pid_t process_id;
	int pipefd[2];

	if(pipe(pipefd)>0)
	{
		cout<<"Error on creating the pipe\n";
	}

	process_id=fork();

	if(process_id>0)
	{
		float array[5] = {12,23,34,45,56};
		close(pipefd[0]); // close the reading end
		char * pointer = "Hi Akshaya Baalaji S, this data is originated by parent process and write on pipe ";
		dataStructure * parentDataStructure =  new dataStructure();
		parentDataStructure->charData = 'a';
		parentDataStructure->intdata = 123;
		// strcpy(parentDataStructure->charPointer,pointer ) ; // for proving memcpy can be used for string also 
		memcpy(parentDataStructure->charPointer,pointer , strlen(pointer)) ; // can be used for string also 
		// strcpy(parentDataStructure->floatPointer,array ) ; // float array cant be copied with strcpy 
		// strcpy working 
		// strcpy can be used for copying a null terminated c style string
		// it copies the charecter from source till it encounter \0 in source  
		memcpy(parentDataStructure->floatPointer,array, sizeof(array)) ;
		write(pipefd[1], parentDataStructure, sizeof(*parentDataStructure));
		close(pipefd[1]);
	}
	else if (process_id == 0)
	{
		close(pipefd[1]);// close the writting end 
		dataStructure * clientDataStructure;
		read(pipefd[0], clientDataStructure, sizeof(*clientDataStructure));
		std::cout<< "Int data = " << clientDataStructure->intdata<<std::endl;
		std::cout<< "Char data = " << clientDataStructure->charData<<std::endl;
		std::cout<< "char data[] = " << clientDataStructure->charPointer<<std::endl;
		std::cout<< "float data[] = " << clientDataStructure->floatPointer[0] <<"  " << clientDataStructure->floatPointer[1] <<"  " << clientDataStructure->floatPointer[2] <<"  " << clientDataStructure->floatPointer[3] <<std::endl;
		close(pipefd[0]);
	}
	else
	{
		cout<<"fork is having a problem \n";
	}
}
