#include <thread>
#include <iostream>
#include <omp.h>

#define thrd_no omp_get_thread_num
using namespace std::chrono;
# define NT 2

static void sequentialFibonacci(){
    auto start = high_resolution_clock::now();
    int a =0;
    int b =1;
    int fibo =0;
    for(int i=0; i < 100; i++){
        fibo = a+b;
        a =b;
        b =fibo;
        std::cout << fibo << std::endl;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout <<" time spends sequential " << duration.count() << std::endl;
}



static int recursiveFibonacci(int a, int b, int fibo, int counter){
    #pragma omp parallel for num_threads(10) private(fibo) shared(a b)
    while(counter < 1){
        return 99;
    }
    
    #pragma opm single 
    fibo = a +b;
    #pragma open task
    a = b;
    b = fibo;
    std::cout <<" sequence " << fibo << std::endl;
    return recursiveFibonacci(a, b, fibo,counter-1);
}


static void sequentialFibonacciParallel(){
    auto start = high_resolution_clock::now();
    int a =0;
    int b =1;
    int fibo =0;
    
    #pragma omp parallel for num_threads(10)
    for(int i=0; i < 10; i++){
        #pragma open task
        std::thread::id this_thread = std::this_thread::get_id();
        // std::cout <<"wait... " << fibo << std::endl;
        fibo = a+b;
        a =b;
        b =fibo;
        std::cout << " fib: " << fibo << std::endl;
        // #pragma open taskwait  
        // std::cout << " MULTIPLE POST IT THREAD ACCUMULATOR: " << this_thread  << std::endl;
        #pragma opm single // only one thread fro the team https://www.youtube.com/watch?v=scoDUiWb6IM 9.54
        // shared clause
        std::cout << "ONLY ONE THREAD" << this_thread << " sequence fibo: " << fibo << std::endl;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout <<" time spends parallel " << duration.count() << std::endl;
}


static int sequentialFibonacciRecursion(int n){
     std::cout << n << std::endl; 
     while (n < 2) {
        return sequentialFibonacciRecursion(n-1) + sequentialFibonacciRecursion(n-2);
      }
      return n;
}



int main(){

    recursiveFibonacci(0, 1, 0, 5);

    //sequentialFibonacciParallel();

    // CREATE TASK NOTES POST IT ACCUMULATES NOTES
    /*
    int n1 = 0;
    int n2 = 1;
    int fibo = 0;
    #pragma omp parallel for num_threads(10)
    for(int i =0; i<10; i++){
            std::thread::id this_thread = std::this_thread::get_id();
            #pragma open task private(fibo)
            fibo = i + n2;
            std:: cout << "Fibo result" << fibo << std::endl;
            // NO RUN UNTIL IS COMPLETE
            #pragma open taskwait 
            #pragma open task private(ni,n2)
             n1=n2;
             n2=fibo;
            std:: cout << i << "  second post it and thread: "<< this_thread  << std::endl;
               // NO RUN UNTIL IS COMPLETE
            #pragma open taskwait 
        }


    */
        /*
        for(int i =0; i<2; i++){
            std::thread::id this_thread = std::this_thread::get_id();
            std:: cout << "notes one no "  << this_thread  <<  "\n" ;
            std:: cout << "notes two no " << this_thread << "\n" ;
            }
        */

}


