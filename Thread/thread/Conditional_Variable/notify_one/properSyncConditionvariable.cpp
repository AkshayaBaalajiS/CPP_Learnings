#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex m;
condition_variable cv;

bool ready = false;
bool processed = false;

int globalData = 12;

void worker()
{
    for (int i = 0; i < 5; i++)
    {
        // simulate work
        this_thread::sleep_for(chrono::milliseconds(1000));

        unique_lock<mutex> lock(m);
        cout << "[worker] waiting...\n";

        cv.wait(lock, [] { return ready; });

        // mutex is locked again here
        globalData += 2;
        cout << "[worker] woke up, globalData = " << globalData << "\n";

        ready = false;
        processed = true;

        lock.unlock();
        cv.notify_one();   // notify main
    }
}

int main()
{
    thread t(worker);

    for (int i = 0; i < 5; i++)
    {
        // simulate producer delay
        this_thread::sleep_for(chrono::milliseconds(1200));

        unique_lock<mutex> lock(m);
        cout << "[main] notifying worker\n";

        ready = true;
        processed = false;

        lock.unlock();
        cv.notify_one();   // wake worker

        // wait until worker finishes this iteration
        unique_lock<mutex> lock2(m);
        cv.wait(lock2, [] { return processed; });
        cout << "[main] worker finished iteration\n";
    }

    t.join();
    cout << "Final globalData = " << globalData << endl;
}
