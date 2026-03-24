#include <semaphore>
#include <iostream>
#include <thread>
#include <chrono>


std::binary_semaphore b1 (0);
std::mutex m1;

void semaphoreZero(){
    b1.acquire();
    std:: cout << "Deadl lock release";
}

void writingMutex(){
    while (true) {
        std::cout << "I enter in the method writing" << "\n";
        m1.lock();
        std::this_thread::sleep_for(std::chrono::seconds(2));
        b1.release();
        m1.unlock();
        std::cout << "I completed my writing" << "\n";
    }
}

void readingMutex(){
    while (true) {
        std::cout << "I enter in the method reading" << "\n";
        m1.lock();
        std::this_thread::sleep_for(std::chrono::seconds(2));
        m1.unlock();
        std::cout << "I completed my reading" << "\n";
    }
}


void writing(){
    while (true) {
        std::cout << "I enter in the method writing" << "\n";
        b1.acquire();
        std::this_thread::sleep_for(std::chrono::seconds(2));
        b1.release();
        std::cout << "I completed my writing" << "\n";
    }
}

void reading(){
    while (true) {
        std::cout << "I enter in the method reading" << "\n";
        b1.acquire();
        std::this_thread::sleep_for(std::chrono::seconds(2));
        b1.release();
        std::cout << "I completed my reading" << "\n";
    }
}


int main(){

    std::thread t3(semaphoreZero);
    std::thread t1(readingMutex);
    std::thread t2(writingMutex);
    t3.join();
    t2.join();
    t1.join();
}

