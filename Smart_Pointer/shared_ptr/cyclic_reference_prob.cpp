#include<iostream>
#include <vector>
#include <memory>
using namespace std;
class Sample1;
class Sample {
public:
    shared_ptr<Sample1> a;
    int d{1120};
    float dd{239.992399};
    ~Sample() {
        cout << "@Sample destroyed\n";
    }
};

class Sample1 {
public:
    shared_ptr<Sample> b;
    int d{10};
    float dd{9.9999};
    ~Sample1() {
        cout << "@Sample1 destroyed\n";
    }
};

int main()
{
	cout<<"@ Shared pointer cyclic reference prgram\n";
	
	shared_ptr<Sample> sharePtr1 = make_shared<Sample>();
	
	shared_ptr<Sample1> sharePtr2 = make_shared<Sample1>() ;
	
	cout<<"USe count of sharePtr1 = " << sharePtr1.use_count() <<endl;
	cout<<"USe count of sharePtr2 = " << sharePtr2.use_count() <<endl;

	sharePtr1->a = sharePtr2;
	sharePtr2->b = sharePtr1;

	cout<<"USe count of sharePtr1 = " << sharePtr1.use_count() <<endl;
	cout<<"USe count of sharePtr2 = " << sharePtr2.use_count() <<endl;

	sharePtr1.reset();
	sharePtr2.reset();
	cout<<"After reset:\n";	
	cout<<"USe count of sharePtr1 = " << sharePtr1.use_count() <<endl;
	cout<<"USe count of sharePtr2 = " << sharePtr2.use_count() <<endl;

	// cout<<"Share Pt member Share ptr hold :"<<sharePtr1->a->d<<endl; 
	// we made the sharedPointer to null on calling reset but member will still hold the address of it and it will die only if the obj is destroyes and this is not destrying cause the inner hold tis value 
}

// without cyclic ownership
// #include<iostream>
// #include <vector>
// #include <memory>
// using namespace std;
// class Sample1;
// class Sample {
// public:
//     // shared_ptr<Sample1> a;
//     ~Sample() {
//         cout << "@Sample destroyed\n";
//     }
// };

// class Sample1 {
// public:
//     // shared_ptr<Sample> b;
//     ~Sample1() {
//         cout << "@Sample1 destroyed\n";
//     }
// };





// int main()
// {
// 	cout<<"@ Shared pointer cyclic reference prgram\n";
	
// 	shared_ptr<Sample> sharePtr1 = make_shared<Sample>();
	
// 	shared_ptr<Sample1> sharePtr2 = make_shared<Sample1>() ;
	
// 	cout<<"USe count of sharePtr1 = " << sharePtr1.use_count() <<endl;
// 	cout<<"USe count of sharePtr2 = " << sharePtr2.use_count() <<endl;

// 	// sharePtr1->a = sharePtr2;
// 	// sharePtr2->b = sharePtr1;

// 	cout<<"USe count of sharePtr1 = " << sharePtr1.use_count() <<endl;
// 	cout<<"USe count of sharePtr2 = " << sharePtr2.use_count() <<endl;

// 	sharePtr1.reset();
// 	sharePtr2.reset();
// 	cout<<"After reset:\n";	
// 	cout<<"USe count of sharePtr1 = " << sharePtr1.use_count() <<endl;
// 	cout<<"USe count of sharePtr2 = " << sharePtr2.use_count() <<endl;

// }