#include <thread>
#include <mutex>
#include <iostream>
#include <omp.h>

#define NT 4

class DeadLockVerification {

    std::mutex x;
    std::mutex y;
    std::mutex DeadLockVerification::xx;
    std::mutex DeadLockVerification::nn;


public:

    void transfer (DeadLockVerification dlx, DeadLockVerification dly, int amount){
           (dlx.xx).lock();
           (dly.nn).lock();

          amount +=5;
          amount +=10;
          std::thread::id this_thread = std::this_thread::get_id();
          std::cout << "Hello alles gut!! " << this_thread; 
    }


    void possibleDeadLock() {

        #pragma omp parallel num_threads(NT)
        {
            int id = omp_get_thread_num();

            if (id % 2 == 0) {
                x.lock();
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                y.lock();
            } else {
                y.lock();
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                x.lock();
            }

            std::cout << "Thread " << id << " acquired locks\n";

            x.unlock();
            y.unlock();
        }
    }
};

int main() {
    DeadLockVerification s;
    std::thread ht1(&DeadLockVerification::transfer, &s);
    ht1.join();


    DeadLockVerification dlx
    DeadLockVerification dly
    transfer(dlx, dly) --> dlx lock --> This thread waitig the dly to unlock
    transfer(dly, dlx ) ---> dly lock  --> This thread waiting for dlx to unlock
}