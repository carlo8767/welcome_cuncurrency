#include <iostream>
#include <thread>
#include <omp.h>
#include <mutex>






int main () {
    std::mutex m1;        
    #pragma omp parallel for collapse(2) num_threads(5)  
        for(int i =0; i<3;i++){
            for(int a =0; a<3;a++){
                m1.lock();
               std::cout << "internal " << a <<" " << omp_get_thread_num() << std::endl;
               m1.unlock();
            }
        }

    std::mutex m2;        
    #pragma omp parallel for num_threads(5)  
        for(int i =0; i<3;i++){
            for(int a =0; a<3;a++){
                m2.lock();
                std::cout << "no collapse " << a <<" " << omp_get_thread_num() << std::endl;
                m2.unlock();
            }
        }
    
    

}