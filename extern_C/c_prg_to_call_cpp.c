#include <stdio.h>
#include "cpp_header.h"

int main()
{
	printf("This is the c program to call cpp program \n");
	cpp_style_print();

	char * ptr = "Akshaya Baalaji Senthilraj";

	wrapperForStringFunc(ptr);
}