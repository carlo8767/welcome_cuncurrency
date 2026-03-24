#include <iostream>
#include <omp.h>
#include <thread>


void test(){



    int n = 6;
    int m = 2;
    int budget = 100;
    int i,j;
    // VARIABLE IN  THE FIRST LOOP PARALEL ARE PRIVATE BY DEFAULT
    // HERE N AND M ARE PRIVATE BY DEFAULT
    // HOWEVER J IS SHARED WITHOU PRIVATE
    #pragma open parallel for private(j)
    //#pragma open parallel for
    for (int i=0; i< n; i++){
        for (int j=1; j< m; j++){
            budget -= 10;
            budget -= 20;
            std:: cout << "inside i is: " << i << " and  budget is  " << budget  << " "
            << " thread is " <<  std::to_string(omp_get_thread_num()) << i << std:: endl;
        }
        budget+=20; 
        std:: cout << "the budget is " << budget << std:: endl;
    }

}

int main () {




    #pragma omp parallel num_threads(4) 
    {
        #pragma omp for nowait
        for(int i =0; i<4;i++){
        std::cout << omp_get_num_threads << " 1 "  << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        } 
        #pragma omp for  nowait
        for(int a =0; a<4;a++){
        std::cout << omp_get_num_threads  << " 2 " << std::endl;
        }
     
    }



}