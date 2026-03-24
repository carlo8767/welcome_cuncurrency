#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex m;
std::condition_variable cv;
std:: binary_semaphore sem (0);

bool ready = false;

void producer() {
    std::lock_guard<std::mutex> lock(m);
    ready = true;
    sem.release();
    cv.notify_one();
}

void consumer() {
    std::unique_lock<std::mutex> lock(m);
    sem.acquire()
    // TODO: wait until ready == true
}
/*
1.
What is the expected value of counter if the program were executed sequentially?
99999
Is the program correct in concurrent execution? Explain why.
No, becasue if the different thread access concurrency at the same, the counter
state value might be different in the memory.
What concurrency problem occurs here?
Data race condition
Fix the program using std::mutex.
int counter = 0;
std::mutex m1;

void increment() {
    m1.lock();
    for (int i = 0; i < 100000; i++) {
        counter++;
    }
    m1.unlock();
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std::cout << counter << std::endl;
}

2.
Why does the mutex make the program correct?
The program is correct becasue the critical section counter++ is access exclusively.
This means that two thread cannot access at the same time in the memory to the value count++
What is the performance problem with this solution?
The problem that every thread must wait an unspecified amount of time in access at the resources.
This might be transform the code in a livelock
Rewrite the function so the mutex is locked fewer times but the result stays correc

void increment() { 
    for (int i = 0; i < 100000; i++) {
        m.lock();
        counter++;
    }
    m.unlock();
}


Explain how a deadlock can occur.
The dealcok will occurs if two thread will lock not in order A B.
For instance:
Thread One access to t1 and lock A after Thread One try to access to the B but  the resources is lock
Thread Two access to t2 and lock B  after Thread Two try to access to the A but  the resources is lock

List the four necessary conditions for deadlock.
No interleaving,
Block and Wait
Circular lock
No mutex
Give one rule that prevents deadlock.
Exectuteh the code in the right order
Introduces interleaving process
Rewrite the code to avoid deadlock.

*/