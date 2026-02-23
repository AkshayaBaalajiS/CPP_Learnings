#include <iostream>
#include <cstring>
#include <memory>

using namespace std;

int main()
{
	cout<<"This is the code to understand the unique_ptr\n";
	
	char array[]= "Hello";
	// cout<<"Size of array = " << (strlen(array)) <<endl;

	// cout<<"pttrr = " << pttrr <<endl;

	cout<<"------Crt way to implement the strcpy--------------\n";
	// below is the replica of the strcpy 
	{	
		char opret[123]; // arrray will be passed as dest in strcpy 
		char * stringg = opret ; // des assigned with some pointer internlly 
		char * arrrr = array ; // source assigned to src pointer on strcpy
		cout<<"Arrr = " << arrrr <<endl;
		while(*arrrr != '\0')
		{
			*stringg = *arrrr;
			stringg++;
			arrrr++;
		}
		cout<<"stringg = " << stringg <<endl;
		cout<<"Arrr = " << arrrr <<endl;
		cout<<"opret = " << opret <<endl;
	}	

	cout<<"--------------------\n";

	cout<<"-------Below is the wrong way to implement the strcpy -------------\n";
	{
		char * stringg = new char[100];  // this is the crt way  // crt 
		
		// char * stringg ; // this is the wrong way to do strcpy  
		char * cpyString = stringg;
		char * arrrr = array ;
		cout<<"cpyString = " << cpyString <<endl; 
		cout<<"Arrr = " << arrrr <<endl;
		// for(int i=0;i<(strlen(array)); i++) //// this is the wrong way to do strcpy  
		while(*arrrr != '\0') // crt 
		{
			*stringg = *arrrr;
			stringg++;
			arrrr++;
		}
		cout<<"stringg = " << stringg <<endl;
		cout<<"Arrr = " << arrrr <<endl;
		cout<<"cpyString = " << cpyString <<endl; // this will print the data cause the cpyString is assigned with string starting address before string modifed the address 
		
		// the same replica in strcpy
		// char * ptr = "Akshaya Baalaji S";
		// char * ptr;
		// char * pttrr = strcpy(ptr, "Akshaya Baalaji S");

	}

	cout<<"--------------------\n";

}


/*
memcpy 
memcpy(dest, src, n);
	It copies exactly n bytes.
	It does NOT care about strings
	It does NOT look for '\0'
	It just copies raw memory
	It is purely byte-based.
*/

/*
strcpy 
strcpy(dest, src);
	It copies characters until it sees '\0' (null terminator).
	So strcpy is:
	A loop that copies byte-by-byte until '\0' is encountered.

char* my_strcpy(char* dest, const char* src)
{
    char* original_dest = dest;

    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';  // copy null terminator

    return original_dest;
}
*/