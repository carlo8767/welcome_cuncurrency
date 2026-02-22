#include <thread>
#include <atomic>
#include <iostream>

class OrderMattersThread{
// VERIFY IF I CAN FLAG THE SEMAPHORE TO 0 AND ANFTER INCREASE



   std:: binary_semaphore simpleT1 {0};
   std:: binary_semaphore simpleT2 {0};


   std::counting_semaphore <3> sem {3};
   std::counting_semaphore <2> semCuncerrent {2};
   std::atomic <bool> stopT1T2 = true;
   std::atomic <bool> stopT3 = true;

   std::atomic_flag flagT1 = ATOMIC_FLAG_INIT;
   std::atomic_flag flagT2 = ATOMIC_FLAG_INIT;

    public:
    void firstThread(){
         while(stopT1T2.load(std::memory_order_acquire)){
         }        
        sem.acquire();
        srand(time(0));
        std::cout << "threadOne" << "\n";
        sem.release();
        stopT3.store(false, std::memory_order_release);
        
    }

    void secondThread(){
        sem.acquire();
        srand(time(0));
        std::cout << "threadTwo" << "\n";
        sem.release();
        stopT1T2.store(false, std::memory_order_release);
    }

    void thirdThread(){
         while (stopT3.load(std::memory_order_acquire) || stopT1T2.load(std::memory_order_acquire)) {
        }
        sem.acquire();
        srand(time(0));
        std::cout << "threadTwo" << "\n";
        sem.release();
    }

    void cuncerrentT1(){
         std::this_thread::sleep_for(std::chrono::milliseconds(2000));
         std::cout << "threadOneCuncerrentT1" << "\n";
         flagT1.clear(std::memory_order_release); // SET TO FALSE
         while (flagT2.test_and_set(std::memory_order_acquire)){  // SET TO TRUE
            }
        std::cout << "both complete" << "\n";
        semCuncerrent.release();
   
    }

     void cuncerrentt2(){
         std::cout << "threadOneCuncerrentT2" << "\n";
         flagT2.clear(std::memory_order_release);
         while (flagT1.test_and_set(std::memory_order_acquire)){  // return True
         }
         std::cout << "both complete" << "\n";
   
    }


    void simpleThreadOne () {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        simpleT1.release();
        std::cout << "waiting t2 complete" << "\n";
        std::cout << "completeT1" << "\n";
        
        simpleT2.acquire();

    }

    void simpleThredTwo () {
        simpleT2.release();
        std::cout << "waiting t1 complete" << "\n";
        simpleT1.acquire();
        std::cout << "completeT2" << "\n";
    }

};

int main () {
    OrderMattersThread ors;

    std::thread t6(&OrderMattersThread::simpleThreadOne, &ors);
    std::thread t7(&OrderMattersThread::simpleThredTwo, &ors);
    t6.join();
    t7.join();


    std::thread t1(&OrderMattersThread::secondThread, &ors);
    std::thread t2(&OrderMattersThread::thirdThread, &ors);
    std::thread t3(&OrderMattersThread::firstThread, &ors);
    t1.join();
    t2.join();
    t3.join();
    std::thread grainOne(&OrderMattersThread::cuncerrentT1,&ors);
    std::thread grainTwo(&OrderMattersThread::cuncerrentt2,&ors);
    grainOne.join();
    grainTwo.join();

   


    return 0;
}