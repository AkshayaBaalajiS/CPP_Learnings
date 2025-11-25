#include <iostream>
using namespace std;

namespace common
{
	class A 
	{
		public:
			A();
			void function();
			void function1();
			void function2();
			void function3();
			~A();
	};
	#include "class.hxx" // as the file is included on namespace no need of namespace there before definition 
}