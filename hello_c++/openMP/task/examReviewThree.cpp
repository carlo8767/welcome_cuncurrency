#include <thread>
#include <iostream>
#include <semaphore>
#include <omp.h>


int array [4]= {0,1,2,3};


void hello_pragma () {

  #pragma omp parallel num_threads(10)
  #pragma omp for nowait
  for(int i =0; i<5; i++){
        // int a = omp_get_num_threads();
        int a = omp_get_thread_num();
        std::cout << "thread number " << a << std::endl; 
    }
    // DIFFERENT REGION
   #pragma omp  for
   for(int b =0; b<5; b++){
        // int a = omp_get_num_threads();
        int bfa = omp_get_thread_num();
        std::cout << "thread number barrier " << bfa << std::endl; 
    }
}



void hello_pragmaSameRegion() {
    #pragma omp parallel num_threads(10)
    {
        #pragma omp for
        for (int i = 0; i < 5; i++) {
            int a = omp_get_thread_num();
            #pragma omp critical
            std::cout << "thread number " << a << std::endl;
        }

        #pragma omp for
        for (int b = 0; b < 5; b++) {
            int bfa = omp_get_thread_num();
            #pragma omp critical
            std::cout << "thread number barrier " << bfa << std::endl;
        }
    }
}


void hello_pragmaSameRegionNowait() {
    #pragma omp parallel num_threads(10)
    {
        #pragma omp for nowait
        for (int i = 0; i < 5; i++) {
            int a = omp_get_thread_num();
            #pragma omp critical
            std::cout << "thread number " << a << std::endl;
        }

        #pragma omp for nowait
        for (int b = 0; b < 5; b++) {
            int bfa = omp_get_thread_num();
            #pragma omp critical
            std::cout << "thread number barrier " << bfa << std::endl;
        }
    }
}


int main(){
hello_pragmaSameRegionNowait();
}






