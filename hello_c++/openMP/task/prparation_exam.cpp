#include <omp.h>
#include <iostream>
#include <thread>

std::mutex m1;

std::counting_semaphore <2> c1 {2};



void exclusive(){
    m1.lock();
    m1.unlock();
}

void reading(){
    c1.acquire();
    
}




void helloOpenMp () {
    int a = 2;
    #pragma omp parallel for private(a)
    for(int i =0; i<10; i++){
        std::thread::id this_thread = std::this_thread::get_id();
        for(int n =0; n<10; n++){
            std::cout << a << " " << this_thread   <<std::endl ;
            a+=20;
        }
    }
}







int main () {
    helloOpenMp();




}