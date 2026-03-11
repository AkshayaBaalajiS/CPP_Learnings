#include <iostream>
#include <cstring>
#include <memory>

using namespace std;

template <typename T>
class Sample
{
	public:
		int a;
		float b;
		T  c;
		Sample(T  ptr, int a=0, float b =0 )  : a(a), b(b), c(ptr) 
		{
			cout<<"Sample class constructor \n";
		}	

		friend ostream & operator<<(ostream & out, Sample & ref)
		{
			out<<ref.a << " " << ref.b <<" " << ref.c << endl ;
			return out;
		}

		~Sample()
		{
			cout<<"~Sample class constructor\n";
		}
};

int main()
{
	cout<<"This is the code to understand the unique_ptr\n";
	char arr[] = "Akshaya Baalaji S";
	char * ptr  = arr;

	Sample<char *> obj(arr);
	cout<<obj;

	cout<<"--------------------------------\n";
	unique_ptr<Sample<char *>> uniPtrSam = make_unique<Sample<char *>>(arr);
	cout<<"uniPtrSam = " << *uniPtrSam ;
	cout<<"--------------------------------\n\n";

	cout<<"--------------------------------\n";
	// 1. unique ptr to shared ptr 
	shared_ptr<Sample<char *>> shaPtrSam = std::move(uniPtrSam);
	cout<<"*shaPtrSam = " << *shaPtrSam;
	// uniPtrSam.reset();
	/*
	Unique ptr to shared ptr can be done 
		unique_ptr guarantees single ownership
		shared_ptr can safely take over and create control block
	*/
	cout<<"--------------------------------\n\n";
	// Attempt 1 
	// cout<<"*uniPtrSam = " << *uniPtrSam ; // this is the error nullptr cause the std::move with unique ptr called s

	// shared ptr to unique ptr cause error so commented uncomment and check the uniqur ptr 
	// cout<<"--------------------------------\n";
	// // 2. Shared Ptr to unique ptr 
	// // design implementation is wrong 
	// unique_ptr<Sample<char *>> uniPtrSam1(std::move(shaPtrSam.get())); // shaPtrSam.get() transfer ownership 
	// // move cant be done cause rhs is sharefd ptr and lhs is unique ptr 
	// // unique_ptr<Sample<char *>> uniPtrSam1 = std::move(shaPtrSam); 
	// // shaPtrSam.get() does not transfer ownership it only return raw pointer 
	// shaPtrSam.reset(); //  reset() would delete the object if use_count was 1
	// /*
	// 	Decreases reference count
	// 	If count becomes 0 → deletes object
	// 	Deletes control block
	// 	does not move raw pointer and set to nullptr 
	// */
	// shaPtrSam = nullptr; // this does not return
	// // cout<<"*shaPtrSam = " << *shaPtrSam;
	// /*
	// Your ownership model is wrong.

	// Correct approach:
	// 	Decide ownership early.
	// 	If single owner → use unique_ptr
	// 	If shared ownership → use shared_ptr
	// */
	// cout<<"--------------------------------\n\n";

	cout<<"--------------------------------\n";
	// Attempt 2 
	// 2. Shared Ptr to unique ptr 
	// design implementation is wrong and the below is not safe way 
	shared_ptr<Sample<char *>> shaPtrSam1 = make_shared<Sample<char *>>(ptr);
	unique_ptr<Sample<char *>> uniPtrSam1 = make_unique<Sample<char *>>(*shaPtrSam1); // shaPtrSam.get() transfer ownership 
	// move cant be done cause rhs is sharefd ptr and lhs is unique ptr 
	// unique_ptr<Sample<char *>> uniPtrSam1 = std::move(shaPtrSam); 
	// shaPtrSam.get() does not transfer ownership it only return raw pointer
	Sample<char *> * samm ;
	cout<<"count shaPtrSam1" << shaPtrSam1.use_count() <<endl;
	if(shaPtrSam1.use_count())
	{
		Sample<char *> * samm = shaPtrSam1.get();
		shaPtrSam1.reset();
	}
	cout<<"count shaPtrSam1" << shaPtrSam1.use_count() <<endl;

	shaPtrSam.reset(); //  reset() would delete the object if use_count was 1
	/*
		Decreases reference count
		If count becomes 0 → deletes object
		Deletes control block
		does not move raw pointer and set to nullptr 
	*/
	shaPtrSam = nullptr; // this does not return
	// cout<<"*shaPtrSam = " << *shaPtrSam;
	/*
	Your ownership model is wrong.

	Correct approach:
		Decide ownership early.
		If single owner → use unique_ptr
		If shared ownership → use shared_ptr
	*/
	cout<<"--------------------------------\n\n";

}
/*
| First Attempt                      | Second Attempt            |
| ---------------------------------- | ------------------------- |
| Reuses SAME raw pointer            | Creates NEW object        |
| Two smart pointers own same memory | Each owns separate memory |
| Double delete                      | Safe                      |
| Ownership conflict                 | No conflict               |
*/
