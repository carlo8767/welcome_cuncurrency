
#include <iostream>
#include <thread>
#include <semaphore>
#include <vector>
#include <mutex>

std::counting_semaphore<1> produce_sem (1);
std::counting_semaphore<1> consume_sem (0);
std::vector<int> buffer = {};


std::counting_semaphore <2> b12 (2);
std::binary_semaphore b34 (0);
std::mutex m1;

void threadOne(){
  b12.acquire();
  for(int i=0; i<10;i++){
    // If I have here the syncronization all the thread progress in parallel
    // 
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    m1.lock();
    std::cout << "First Thread "  <<  i << std::endl;
    m1.unlock();
    // b34.release(); 
  }
  // EXAMPLE OF DEADLOCK
  b34.release();
}

void threadTwo(){
  for(int i=0; i<10;i++){
    b12.acquire();
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    m1.lock();
    std::cout << "Second Thread " <<  i <<  std::endl;
    m1.unlock();
    b34.release();
  }
}

void threadThree(){
  for(int i=0; i<10;i++){
    b34.acquire();
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    m1.lock();
    std::cout << "Third Thread " <<  i << std::endl;
    m1.unlock();
    b12.release();
    }
}

void threadFourth(){
    for(int i=0; i<10;i++){
        b34.acquire();
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        m1.lock();
        std::cout << "Fourth Thread " <<   i << std::endl;
        m1.unlock();
        b12.release();
   }
}


void produce(){
    for(int i=0; i<3;i++){
        produce_sem.acquire();
        buffer.emplace_back(1);
        std::cout << "Produced one unit." <<  std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        consume_sem.release();
    }
}
void consume(){
    for(int i=0; i<3;i++){
        consume_sem.acquire();
        // MISS LOCK 
        buffer.pop_back();
        std::cout << "Consumed one unit." << std::endl;
        produce_sem.release();
    }
}
int main(){
    std::thread produce_thr(produce);
    std::thread consume_thr(consume);
    produce_thr.join();
    consume_thr.join();

    std::thread t1(threadOne);
    std::thread t2(threadTwo);
    std::thread t3(threadThree);
    std::thread t4(threadFourth);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
}