#include <thread>
#include <iostream>
#include <omp.h>

#define thrd_no omp_get_thread_num
using namespace std::chrono;

// Recursive fibonacci
static int sequentialFibonacci(int n){
      if (n < 2) {
         return 1;
    }
    int x, y;
    x = sequentialFibonacci(n-1);
    y = sequentialFibonacci(n-2);
    return x +y;
}


static int recursiveFibonacciParallel(int n){
    std::thread::id this_thread = std::this_thread::get_id();
    
    if (n < 2) {
         return 1;
    }
    int x, y;
      #pragma omp task shared(x)
      x = recursiveFibonacciParallel(n-1);
      #pragma omp task shared(y)
      y = recursiveFibonacciParallel(n-2);
      #pragma omp taskwait // ORDER PRESERVE
      return x + y;
   }
   


int main(){
   
   auto start_seq = high_resolution_clock::now();
   for(int i =0; i<30;i++){
      int values = sequentialFibonacci(i);
       std:: cout << "sequential order "<< values  << std::endl;
   }
    auto stop_seq = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop_seq - start_seq);
    std::cout <<" time spends sequential " << duration.count() << std::endl;
    
   auto start_parallel = high_resolution_clock::now();
   #pragma omp parallel
   {
      #pragma omp single // BOSS AREA REGION
      {
         #pragma omp taskloop  // SLAVE // create number of  sub task
         for(int i =0; i < 30; i++){
               if (i <= 10){
                   int seq = sequentialFibonacci(i);
                   std::cout  << "seq " << seq << std::endl;
               }
                
               else{
                  int ps =recursiveFibonacciParallel(i);
                  std::cout  << "parallel " << ps << std::endl;
               }
               
         }
      }
   }
   auto stop_parallel = high_resolution_clock::now();
   auto duration_paralllel = duration_cast<microseconds>(stop_parallel - start_parallel);
   std::cout <<" time spends parallel " << duration_paralllel.count() << std::endl;

   // https://hpc2n.github.io/Task-based-parallelism/branch/master/task-basics-2/
   
}