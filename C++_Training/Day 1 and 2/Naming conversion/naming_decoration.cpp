#include<stdio.h>
/*
.file	"naming_decoration.cpp"
	.text
	.globl	_Z4gfunv  #Here 
	.def	_Z4gfunv;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z4gfunv
_Z4gfunv:
when we have a function call with no argument it is decorated as gfunv (gfun)void argument 


	.globl	_Z4gfuni
	.def	_Z4gfuni;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z4gfuni
_Z4gfuni:
When we do a function call with argument in it . The name is decorated as (gfun)integer argument 


this makes the difference bet C and C++ to make the C++ to do the function overloading 


	.seh_endproc
	.globl	_Z4gfund
	.def	_Z4gfund;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z4gfund
_Z4gfund:
.LFB47:
When we do a function call with arguments in it the name is decorated based on type of argument (gfun)double argument 
*/
void gfun()
{
    int a=10;
}

void gfun(int a )
{
    int b =a ;
}
void gfun(double a )
{
    float b =a ;
}


int main()
{
    gfun(); // function call 
    // when we have a function call with no argument it is decorated as gfunv (gfun)void argument 
    gfun(10);
    // When we do a function call with argument in it . The name is decorated as (gfun)integer argument 
    gfun(11.12);
    // When we do a function call with arguments in it the name is decorated based on type of argument (gfun)double argument 


}