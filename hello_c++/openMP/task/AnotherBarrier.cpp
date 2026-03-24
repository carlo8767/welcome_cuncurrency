#include <omp.h>
#include <iostream>
#include <vector>
#include <semaphore>


std::counting_semaphore <10> s1 (9);





void teamThread(){
    #pragma omp parallel num_threads (5)
    {
            #pragma omp for
            for(int i=0; i<10; i++){
            std::cout<< omp_get_thread_num();
            }

              #pragma omp for
            for(int a=0; a<10; a++){
            std::cout<< omp_get_thread_num();
            }
        
    }
}




int main () {
    std::vector <int> vi = {3,3,4};
    vi.push_back(1);
    vi.erase(vi.begin()+0);
}