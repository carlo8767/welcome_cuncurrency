#include <array>
#include <iostream>
#include <omp.h>
#include <mutex>
int main() {

std::mutex m1;
// EFFECT THE NUMBER OF CHUNCK
#pragma omp parallel for schedule(static,1) num_threads(3)
for (int i = 0; i < 5; i++) {
    m1.lock();
    std::cout << "Thread " << omp_get_thread_num()
              << " handles i = " << i << std::endl;
    m1.unlock();
}

#pragma omp parallel for schedule (dynamic,1) num_threads (10)
for (int i = 6; i < 60; i++) {
    m1.lock();
    std::cout << "Thread " << omp_get_thread_num()
              << " handles i = " << i << std::endl;
    m1.unlock();
}
}


/*
    const int n = 10;
std::array<float,n> temperature = {8,1,1,1,1,1,1,1,1,4};
std::array<float,n> newTemperature{};
/// YOu need mutex here because there is a data condition
#pragma omp parallel for
for (int i=0; i < temperature.size();i++)
{
    if (i < temperature.size()-1) {
         newTemperature[i+1] += temperature[i]/2;
    }
   
    if (i > 0) {
         newTemperature[i-1] += temperature[i]/2;
    }
       
}


*/


