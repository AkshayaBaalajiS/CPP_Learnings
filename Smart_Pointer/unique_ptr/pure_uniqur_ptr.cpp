#include <iostream>
#include <memory>

using namespace std;

template <typename T>
class Sample
{
	public :
		Sample()
		{
			cout<<"@Sample()\n";
		}

		Sample(int a , float b)
		{
			cout<<"@Sample(int a , float b)\n";
		}
};


// try creation of custom makeuniquee
template <typename T, typename... TT>
unique_ptr<T> makeuniquee(TT&&... args)
{
	return make_unique<T>(args...);
} 


int main()
{
	// 1 way to intialize 
	unique_ptr<Sample<int>> uni = make_unique<Sample<int>>();

	// 2 way to initialize
	unique_ptr<Sample<int>> uni1;
	uni = std::move(uni1);

	// 3 way to initialize
	unique_ptr<Sample<int>>uni2(new Sample<int>());


	/*
	// 4 way to initialize 

	static Sample<int> obj;
	unique_ptr<Sample<int>>uni3(&obj);
	“I own this object and I will destroy it using delete when I die.”

		So internally, unique_ptr will do:

		delete ptr;

	But obj is NOT heap-allocated
	delete &obj;   // ❌ undefined behavior

	*/

	unique_ptr<Sample<float>>uni4 = makeuniquee<Sample<float>>(123,232.23423);
}