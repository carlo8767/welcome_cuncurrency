#include <iostream>
#include <thread>
#include <semaphore>
#include <chrono>

std::counting_semaphore<1> horizontal(0);
std::counting_semaphore<1> vertical(1);

void horizontalCrossing(){
    while(true){
        horizontal.acquire();
        std::cout << "Car going through horizontal road." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 1000)); 
        vertical.release();
    }
}

void verticalCrossing(){
    while(true){
        vertical.acquire();
        std::cout << "Car going through vertical road." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 1000)); 
        horizontal.release();
    }
}

int main(){
    srand(time(0));
    std::thread horizontalCross(horizontalCrossing);
    std::thread verticalCross(verticalCrossing);

    horizontalCross.join();
    verticalCross.join();
}