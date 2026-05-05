#include <thread>
#include <iostream>
#include <semaphore>
#include <mutex>

std::counting_semaphore <3> b3 (1);
int flag = 0;
std:: mutex m1;

// HOW YOU ARE ABLE TO DETECT THE NUMBER OF OPERATIONS . IF T1 HAS 2 OPERATION AND T3 HAS 4 OPERATIONS T3 IT WILL ENCOUNTER A DEADLOCK

void runT1 () {
    for(int i=0; i<2; i++){
    std::this_thread::sleep_for(std::chrono::seconds(2));
    m1.lock();
    std::cout << "Thread one run" << std::endl;
    m1.unlock();
    b3.release();
    }
    flag = 1;
}


void runT3 () {
    for(int i=0; i<4; i++){
    b3.acquire();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    m1.lock();
    std::cout << "Thread three run" << std::endl;
    m1.unlock();
    }
}


int main () {

    std::thread t1 (runT1);
    std::thread t3 (runT3);
    t1.join();
    t3.join();
}