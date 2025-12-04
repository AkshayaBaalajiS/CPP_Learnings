#include <iostream>
#include <functional>
using namespace std;

void function12(void (*lamFunptr) ())
{
	lamFunptr(); 
}



int main()
{
	auto lambdafunc = []()
	{
		cout<<"@ lambda function\n";
	};

	lambdafunc();

	void (*lamFunptr) () = lambdafunc;
	std::function<void ()> funcPtrLam = lambdafunc;

	lamFunptr();
	funcPtrLam();
	function12(lamFunptr);
}