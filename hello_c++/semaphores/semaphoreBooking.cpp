#include <iostream>
#include <thread>
#include <semaphore>
#include <chrono>

std::counting_semaphore<3> booking(3);

void book(){
    booking.acquire();
    std::cout << "Booked a room." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 10000)); 
    st  d::cout << "Released a room." << std::endl;
    booking.release();
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