#include <iostream>
#include <thread>
#include <semaphore>
#include <chrono>


std::counting_semaphore<3> booking(3);

void book(){
    //if (booking.try_acquire_for(std::chrono::milliseconds(1000))){
    if (booking.try_acquire()){
        std::cout << "Booked a room." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 1000)); 
        std::cout << "Released a room." << std::endl;
        booking.release();
    }

}


int main(){
    srand(time(0));
    std::thread t1(book);
    std::thread t2(book);

    srand(time(0));
    std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 1000)); 

    std::thread t3(book);
    std::thread t4(book);
    std::thread t5(book);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
}