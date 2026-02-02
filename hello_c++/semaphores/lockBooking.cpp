#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex booking;

void book(){
    booking.lock();
    std::cout << "Booked a room." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 10000)); 
    std::cout << "Released a room." << std::endl;
    booking.unlock();
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