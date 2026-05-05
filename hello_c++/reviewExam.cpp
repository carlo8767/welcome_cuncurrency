// part1.cpp — Thread Precedence Graph
// Compile: g++ --std=c++20 -pthread part1.cpp -o part1

#include <iostream>
#include <thread>
#include <mutex>
#include <semaphore>

using namespace std;


// TODO: Declare your semaphores and mutex here.
/*
Mutex ensure the resource is access exclusively by a single thread
The thread own the resources in the only that can release the lock.
This is ensure the mutual exclusion.


*/
mutex mu;
binary_semaphore sem1(1);
binary_semaphore sem2(0);
binary_semaphore sem3(0);
binary_semaphore sem3_5(0);
binary_semaphore sem4(0);
binary_semaphore sem4_5(0);



void thread_T1() {
    for (int cycle = 1; cycle <= 5; cycle++) {
        sem1.acquire();
        mu.lock();
        cout << "T1 ";
        mu.unlock();
        sem2.release();
    }
}

void thread_T2() {
    for (int cycle = 0; cycle < 5; cycle++) {
        
      sem2.acquire();
      mu.lock();
      cout << "T2 ";
      mu.unlock();
      sem3.release();
      sem4.release();
    }
}

void thread_T3() {

    for (int cycle = 0; cycle < 5; cycle++) {
        sem3.acquire();
        mu.lock();
        cout << "T3 ";
        mu.unlock();
        sem3_5.release();
      
    }  
}

void thread_T4() {
  
    for (int cycle = 0; cycle < 5; cycle++) {
        sem4.acquire();
        mu.lock();
        cout << "T4 ";
        mu.unlock();  
        sem4_5.release();
    }
  }

void thread_T5() {
    for (int cycle = 0; cycle < 5; cycle++) {
        sem3_5.acquire();
        sem4_5.acquire();
        mu.lock();
        cout << "T5 " << endl;
        mu.unlock();
        sem1.release();
    }
}

int main() {
    thread t1(thread_T1);
    thread t2(thread_T2);
    thread t3(thread_T3);
    thread t4(thread_T4);
    thread t5(thread_T5);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    cout << "All cycles complete." << endl;
    return 0;
}