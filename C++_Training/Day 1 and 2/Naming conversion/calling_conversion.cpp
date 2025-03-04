/*
Calling conversions :
stdcall
void __attribute__((stdcall)) gfun(int a ,int b)  in g++
void __stdcall gfun(int a ,int b)  in g++


Calling convertion :
stdcall : calle unwinds the stack for its arguments
cdecl : caller unwinds the stack for calley arguments    (kgwars in python )
fastcall : Supported in VC++ no gcc 
thiscall : from c++ onwards  
*/

//vairable number of arguments 
//void myfun(int n , ....);
/*
void function()
{
	function();
	function(1,10);
	function(2 , 20 , 10 );
}


*/
void gfun(int a , int b)
{
	int c=10 , d=20 ;
}
void main()
{
	gfun(10,20);
}