#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <chrono>
#include <iostream>
#include <mutex>
using namespace std::chrono;
#define N 1000

double A[N][N], B[N][N], C[N][N];
std::mutex m1;

void init_matrices() {
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
            C[i][j] = 0;
        }
}

void multiply_sequential() {
    auto start = high_resolution_clock::now();
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            for(int k = 0; k < N; k++)
                C[i][j] += A[i][k] * B[k][j];
    auto end = high_resolution_clock::now();
    auto total_time = end - start;
    std::cout << "The time sequential is " <<  total_time << std::endl;
}

void multiply_parallel () {
    auto begin = high_resolution_clock::now();
    #pragma omp parallel for collapse(3) reduction(+ : C)
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            for(int k = 0; k < N; k++)
                C[i][j] += A[i][k] * B[k][j];
    auto end = high_resolution_clock::now();
    auto total_time = end - start;
    std::cout << "The time paralllel is " << total_time << std::endl;
}




int main() {
    init_matrices();

    
    multiply_sequential();
    multiply_parallel();


    return 0;
}