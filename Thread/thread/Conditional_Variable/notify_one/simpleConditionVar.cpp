#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex m;
std::condition_variable cv;
bool ready = false;

void worker() {
    std::unique_lock<std::mutex> lock(m);

    cv.wait(lock, [] { return ready; });  
    // thread sleeps here

    std::cout << "Worker thread running\n";
}

int main() {
    std::thread t(worker);

    std::this_thread::sleep_for(std::chrono::seconds(2));

    {
        std::lock_guard<std::mutex> lock(m);
        ready = true;
    }

    cv.notify_one();
    t.join();
}
