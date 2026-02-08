#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>

using namespace std;

bool ready1 = false;
bool ready2 = false;

mutex m1;
condition_variable c1;
condition_variable c2;


int global_variable =12;

void function()
{
	for(int i=0;i<10;i++)
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		unique_lock<mutex>ul(m1);
		c1.wait(ul, []{return ready1; }); 
		/*
		while (!ready1) {
			// ---- THIS IS THE MAGIC ----
			ul.unlock();        // mutex released
			sleep();            // thread parked by OS
			ul.lock();          // mutex reacquired after notify
		}	
		*/
		/*
		If main() holds the mutex and calls notify_one(), the sleeping thread wakes up, tries to lock the mutex, fails (because main() still holds it), and waits until main() releases the mutex.
		*/
		global_variable+=12;
		ready1=false;
		auto endTime = std::chrono::high_resolution_clock::now();
		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		cout<<"[Function] Wait time = " << dura.count() <<endl;

		std::this_thread::sleep_for(std::chrono::milliseconds(1232));
		ready2=true;
		c2.notify_one();
	}
}

int main()
{
	cout<<"This is the program to understand the condition variable and the usage of it ";
	thread t1(function);
	for(int i=0;i<10;i++)
	{
		// unique_lock<mutex> ul1(m1);
		/* what if the main hold the mutex before notify one 
		If main() holds the mutex and calls notify_one(), the sleeping thread wakes up, tries to lock the mutex, fails (because main() still holds it), and waits until main() releases the mutex.
		*/

		std::this_thread::sleep_for(std::chrono::milliseconds(2323));
		ready1=true; // if this is happening first whithout delay at top of this line then the thread function will have the pred as true and the wait of the function will be 0
		global_variable/=12;
		// c1.notify_one(); // if notify is commented with only predicate we cant make a sleeping thread wake up 
		c1.notify_one(); 
		/*
		“notify_one wakes the sleeping thread,
		then inside wait the mutex is locked again and execution continues,
		and when the lock object goes out of scope the mutex is unlocked.”
		*/
		unique_lock<mutex> ul(m1); //trying to lock the same mutex twice in the same thread ⇒ deadlock
		/*
		the main thread blocks forever
		it is waiting for itself to unlock the mutex
		but it never reaches the end of scope of ul1
		*/
		/*
		ul is constructed
		ul locks m1
		Now the function thread owns the mutex
		*/
		auto startTime = std::chrono::high_resolution_clock::now();
		c2.wait(ul, []{return ready2;});
		auto endTime = std::chrono::high_resolution_clock::now();
		auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		ready2=false;
		cout<<"[main] Wait time = " << dura.count() <<endl;
	}
	t1.join();
	cout<<"global_variable_At last =" << global_variable <<endl;

	// int * ptrr = new int(10);
}

/*
 * 
c1.wait(ul, [] { return ready1; });
Is equivalent to this exact logic (simplified but accurate):

while (!ready1) {
    c1.wait(ul);   // unlocks mutex and sleeps
}

Lock mutex

Check predicate

If predicate is true
→ return immediately
→ ❌ no blocking
→ ❌ no notify needed

If predicate is false
→ unlock mutex
→ sleep until notified
→ re-lock mutex
→ re-check predicate


Your core doubt (rephrased clearly)

“If the predicate controls everything (true / false), why do we even need notify_one()?
Why can’t we just change the predicate and let the thread run?”

This is the exact right question.

The short, correct answer 🔥

Because changing a predicate does NOT wake a sleeping thread.

A sleeping thread will never re-check the predicate on its own.

It must be explicitly woken up — and that is what notify_one() does.
*/