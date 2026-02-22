#include <semaphore>
#include <thread>
#include <iostream>

using namespace std;

class Concurrency {
public:


    std::counting_semaphore<1> sem{1};

    void resources() {
        sem.acquire();
        std::thread::id this_id = std::this_thread::get_id();
        std::cout << "[thread] Got the signal\n";
        sem.release();
    }
};

int main() {
    Concurrency c;

    std::thread t1(&Concurrency::resources, &c);
    std::thread t2(&Concurrency::resources, &c);
    t1.join();
    t2.join();
}