#include<stdio.h>


void gfun(int a , int b)
/*
+ it is receiving the varibale from diff func 
- it is a where it is created 
Offset of argument = + (the sum  of the number of argument declared before + sizeof(context_switch))    // contect switching is the sum of number of the registers in user stack 
	offset(a) = + (0 + 8 )  / here 8 because 4 + 4 - 8 2 registers main and gfun 
	offset(b) = + (4 + 8 )  / here 8 because 4 + 8 - 12 2 registers main and gfun 
	


*/
{//prologue  THis set the environment setup for the body of the function 
	/*
	push ebp 
		sub sizeof(int) , ebp
		mov ebp , ESP  
	mov ESP , EBP // overwrite EPB with ESp value 
		sub sizeof(int) , ebp
	
	int c=5 , d=6 
		foR 2 LOCAL VARIABLE 
			sub esp , sizeof(int) 
			sub esp , sizeof(int)
		offset(a) ->  -(The sum of the size of the locals declared before  + sizeof(itself) ) 
			offset(a) - > -(0 +4 ) - > -4 
			offset(b ) - > - (4 + 4) - > -8
			
		Initialization : 
			int c =10 , d=10;
			mov 10 ,c             / written in Source , destination g++ way in windows destination first and value next 
			mov 20 ,d             / written in Source , destination g++ way
				mov   c , acc    -> ebp + offset(a)   / written in Source , destination g++ way   -> 1000 + -4  = 996
				mov   d , acc      -> ebp + offset(a)   / written in Source , destination g++ way   -> 1000 + -8  = 992
				mov	  c  , acc    -> ebp + offset(a)   / written in Source , destination g++ way   -> 1000 + -4  = 996
	
	*/
	/*
	a= c+d - b 
		
		mov   c , Acc    -> ebp + offset(c)      -> 1000 + -4  = 996 // for many initialization reduce accordingly 
		add ln , Acc      -> ebp + offset(d)            -> 976 + - (8)  = 968
		sub b , Acc     -> ebp + offset(b)    -> 		976  + 8 = 984
		mov Acc , a -> ebp + offset(a) ->     984 + (12)  = 992
		
	*/
	int c=5 , d=45;
}///epilogue  this removes the environment setup when comming out of function 
/*
	add sizeof(locals ) , esp    ALU operation done by optimizer 
		or 
	move ebp , esp			Register to register operation is fater comparing to ALu 
	
	
	pop ebp 
		mov  ebp , esp 


*/


int main()
{
	int a=10 , b=10;
	/*
	Declaration
	Definition   - assignment of the varibale in memory based on scope here it get allocated to Stack segment memory 
		COmpiler does :
			COmpiler substract the ESP by sizeof(int) variable 
			in 1 pass compiler 
				foR 2 LOCAL VARIABLE 
					sub esp , sizeof(int) 
					sub esp , sizeof(int) 	
			in 2 pass compailer 
				This will get number of tokens at first and 
					sub esp , sizeof(locals)  // 2 varible 
	Initialization : 
	int a =10 , b=10;
	mov 10 ,a             / written in Source , destination g++ way in windows destination first and value next 
	mov 20 ,             / written in Source , destination g++ way
		mov   a , acc    -> ebp + offset(a)   / written in Source , destination g++ way   -> 1000 + -4  = 996
		mov   b , acc      -> ebp + offset(a)   / written in Source , destination g++ way   -> 1000 + -8  = 992
		mov	  a  , acc    -> ebp + offset(a)   / written in Source , destination g++ way   -> 1000 + -4  = 996
	
	offset(a) ->  -(The sum of the size of the locals declared before  + sizeof(itself) ) 
		offset(a) - > -(0 +4 ) - > -4 
		offset(b ) - > - (4 + 4) - > -8
	
	a= a + b ;
		mov   a , acc    -> ebp + offset(a)      -> 1000 + -4  = 996
		mov   b , acc      -> ebp + offset(a)     -> 1000 + -8  = 992
		mov	  a  , acc    -> ebp + offset(a)    -> 1000 + -4  = 996

 	
	Big Endian :
		
	
	*/
	
	/*
	Code Segment :
		This begins from the main part in code segment 
		void gfunc(int a,int b);
			consider main start from the 100 address 
			101 push (a)
				sub esp , sizeof(int)   // here to put the size of the varibale the declaration of the function is needed 
				mov a , Acc (Accumulator)
			102 push (b)
				sub esp , sizeof(int)   // here to put the size of the varibale the declaration of the function is needed 
				mov b , Acc (Accumulator)
			103 call gfun()
				push (PC)
					sub sizeof(a) , esp 
					mov a , esp
				mov addressof(gfun()) , PC 
					moves the address of the function in the code segment to meomory to the PROgram Counter 
					Because of the function call 
	
	*/
}