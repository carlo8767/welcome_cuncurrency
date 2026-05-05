#include <iostream>
#include <thread>
#include <omp.h>
#include <mutex>
using namespace std::chrono;

int main () {

    // Use reduction to avoid race condition
    // and optimize performance to run in parallel a sum
    std::mutex m1;
    int sumA = 0;
    auto startA = high_resolution_clock::now();        
    #pragma omp parallel for reduction(+:sumA) num_threads(5)  
        for(int i =0; i<900000000;i++){
               sumA+=i;
              // m1.lock();
              // std::cout << "internal " << i <<" " << omp_get_thread_num() << std::endl;
              // m1.unlock();
            
        }
    auto stopA = high_resolution_clock::now();
    auto durationA = duration_cast<microseconds>(stopA - startA);
    std::cout <<" time spends reduction " << durationA.count() << std::endl;
    std::cout << "the total sum is  "  << sumA << std::endl;
    // NO REDUCTION
    std::mutex m2; 
    int sum = 2;
    // Automatically detect type
    auto start = high_resolution_clock::now();     
    #pragma omp parallel for  num_threads(5)  
    for(int i =0; i<900000000;i++){
        sum+=i;
        // m2.lock();
        // std::cout << "no collapse " << i <<" " << omp_get_thread_num() << std::endl;
       //  m2.unlock();
        
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout <<" time spends sequential " << duration.count() << std::endl;
    std::cout << "the total sum is  "  << sum << std::endl;
    

}