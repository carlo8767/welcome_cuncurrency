#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <chrono>
#include <iostream>
#include <mutex>
#include <semaphore>
#include <thread>

#define N 5
std::mutex m1;
std::counting_semaphore <N> forksAvailabel [N];


void philosphersOne (int sit){
    for(int plate=0; plate < 4; plate++){
        forksAvailabel[(sit)%N].acquire();
        forksAvailabel[(sit+1)%N].acquire();
        m1.lock();
        std::cout << "philospher one even is eating" << std::endl;
        m1.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        forksAvailabel[sit].release();
        forksAvailabel[(sit+1)%N].release();

    }
    
}

void philosphersTwo (int sit){
    for(int plate=0; plate < 4; plate++){
        forksAvailabel[sit].acquire();
        forksAvailabel[(sit+1 % N)].acquire();
        m1.lock();
        std::cout << "philospher two even is eating" << std::endl;
        m1.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        forksAvailabel[sit].release();
        forksAvailabel[(sit+1)%N].release();

    }

}

void philosphersThree (int sit){
    for(int plate=0; plate < 4; plate++){
            forksAvailabel[(sit)%N].acquire();
            forksAvailabel[sit+1].acquire();
            m1.lock();
            std::cout << "philospher three even is eating" << std::endl;
            m1.unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            forksAvailabel[sit].release();
            forksAvailabel[(sit+1)%N].release();
        
    }

}
void philosphersFours (int sit){
    for(int plate=0; plate < 4; plate++){
            forksAvailabel[sit].acquire();
            forksAvailabel[(sit+1)%N].acquire();
            m1.lock();
            std::cout << "philospher Four even is eating" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            m1.unlock();
            forksAvailabel[sit].release();
            forksAvailabel[(sit+1)%N].release();

    }
}

int main () {
    std::thread t1 (philosphersFours,0);
    std::thread t2 (philosphersThree,1);
    std::thread t3 (philosphersTwo,2);
    std::thread t4 (philosphersOne,3);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
}
