# define NT 10
#include <omp.h>
#include <stdio.h>
#define thrd_no omp_get_thread_num

int main (){

    

    #pragma omp parallel for num_threads(NT)
    // PRAG 1
    for(int i=0; i<NT; i++)
        printf("thrd no %d\n",thrd_no());
}