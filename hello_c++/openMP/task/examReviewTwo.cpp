#include <thread>
#include <iostream>
#include <semaphore>


std::string a = "";
std::string b = "";

std::mutex m1;
std::mutex m2;
std::binary_semaphore b1 {0}, b2 {0} ;
/// std::binary_semaphore buffer {0} ;
std::counting_semaphore <3> s1 (10);
void consumer(){
  
   for (int i=1;i<20;i++) {
      s1.acquire();
      std::this_thread::sleep_for(std::chrono::seconds(1));
      std::cout << "consume buffer" << std::endl ;
      
   }
}

void producer(){
    for (int i=1;i<20;i++) {
        std::this_thread::sleep_for(std::chrono::seconds(5));
        s1.release();
        std::cout << "produces buffer" << std::endl ;
        
    }
}

void try_access(){
        if (b1.try_acquire()) {
            std::cout << "Hello" << std::endl;
        }
        else {
            std::cout << "False" << std::endl;
            b1.release();
        }
    }

int main () {
    std::thread t1 (try_access);
    t1.join();
    std::thread t2 (try_access);
    t2.join();
    std::thread t3 (producer);
    std::thread t4 (consumer);
    t3.join();
    t4.join();
}