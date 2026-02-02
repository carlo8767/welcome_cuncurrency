#include <chrono>
#include <iostream>
#include <thread>
#include <utility>
#include <string>
#include <mutex>
#include <unistd.h>



class ThreadHello {

    public: int number;
    public: std::mutex createLock;

    ThreadHello(int value){
        // Arrow operator
        number = value;
    }

    int getNumber(){
        return this->number;
    }

    void printResult(){
        std::lock_guard  <std::mutex> lock(createLock);
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "Hello thread " << getpid() << "\n";
    }


};

int main () {
        ThreadHello t1 =  ThreadHello(2);
        ThreadHello t2 = ThreadHello(3); // POINTER
        std::thread ht1(&ThreadHello::printResult, &t1);
        std::thread ht2(&ThreadHello::printResult, &t2);
        t1.printResult();
        t2.printResult();
        ht1.join();
        ht2.join();

}

