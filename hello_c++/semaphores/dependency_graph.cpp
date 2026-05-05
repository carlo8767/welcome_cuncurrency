#include <thread>
#include <iostream>
#include <semaphore>

std::binary_semaphore b1 (0);
std::binary_semaphore b2 (1);
std::binary_semaphore b3 (0);
std::mutex m1;


void runT1 () {
    for(int i=0; i<3; i++){
    b1.acquire();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Thread one run" << std::endl;
    b3.release();
    }
}

void runT2 () {
    for(int i=0; i<3; i++){
    b2.acquire();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Thread two run" << std::endl;
    b1.release();
    }
}

void runT3 () {
    for(int i=0; i<3; i++){
    b3.acquire();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Thread three run" << std::endl;
    b2.release();
    }
}


int main () {

    std::thread t1 (runT1);
    std::thread t2 (runT2);
    std::thread t3 (runT3);
    t1.join();
    t2.join();
    t3.join();
}