#include <thread>
#include <iostream>
#include <semaphore>
#include <atomic>
using namespace std;

class LaboratoryThree {
public:

    int age;
    // BINARY SEMAPHORE
    std::binary_semaphore ts {1};

    std::counting_semaphore<2> s1{2};
    std:: mutex m1;
    std::atomic<bool> stopFlag = true;

    void threadOne(){
        s1.acquire();
        std::cout << "its run thread One" << "\n";
        stopFlag.store(false, std::memory_order_release);
        ts.release();
    }
    
    void threadTwo(){
        while (stopFlag.load(std::memory_order_acquire)){
        }
        s1.acquire();
        std::cout << "its run thread Two" << "\n";
        s1.release();
    }
    
    
    void getNameThread() {
        s1.acquire();
        std::thread::id this_id = std::this_thread::get_id();
        std::cout << "The thread number is " << this_id << "\n";
        s1.release();
    }
};

int main() {
    // GENERATE NUMBER AND SET SEED
    /*
        int x = time(0);
    srand(x);
    cout << 1 + rand()%6 << endl;
    cout << 1 +rand()%6 << endl;
    cout << 1 +rand()%6 << endl;

    LaboratoryThree ns;

    std::thread t1(&LaboratoryThree::getNameThread, &ns);
    t1.join();

    */

    LaboratoryThree b = LaboratoryThree();
    std::thread b1(&LaboratoryThree::threadOne, &b);
    std::thread b2(&LaboratoryThree::threadTwo, &b);
    b1.join();
    b2.join();



    return 0;
}