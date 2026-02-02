#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex booking1;
std::mutex booking2;
std::mutex booking3;

void book(){
    while (true){
        booking1.lock();
        std::cout << "Booked room 1." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 10000)); 
        std::cout << "Released room 1." << std::endl;
        booking1.unlock();

        booking2.lock();
        std::cout << "Booked room 2." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 10000)); 
        std::cout << "Released room 2." << std::endl;
        booking2.unlock();

        booking3.lock();
        std::cout << "Booked room 3." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 10000)); 
        std::cout << "Released room 3." << std::endl;
        booking3.unlock();
    }
}


int main(){
    srand(time(0));
    std::thread t1(book);
    std::thread t2(book);

    std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 100)); 

    std::thread t3(book);
    std::thread t4(book);
    std::thread t5(book);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
}