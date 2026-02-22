
#include <semaphore>

#include <semaphore>
#include <thread>
#include <iostream>
using namespace std;

class Producer {
    public:
std::counting_semaphore<1> sem{1};



    void resources (){
        sem.acquire();
        std::cout << "[thread] Got the signl\n";
        sem.release();
    }


};




int main () {
    std:: thread 
}
