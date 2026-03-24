#include <iostream>
#include <thread>
#include <mutex>
#include <omp.h>
using namespace std;

int counter = 0;
mutex mtx;

void increment()
{   
    mtx.lock();
    for (int i = 0; i < 250000; i++)
    {
        counter++;
    }
    mtx.unlock();
}


void increments_improvment()
{   
    int localCounter = 0;
    for (int i = 0; i < 250000; i++)
    {
        localCounter++;
    }
    mtx.lock();
    counter += localCounter;
    mtx.unlock();
}

void incrementPragma(){
    #pragma omp parallel num_threads (4) {
        for (int i = 0; i < 250000; i++)
        {
            counter++;
        }
    }
    


}

int main()
{
    thread t1(increment);
    thread t2(increment);
    thread t3(increment);
    thread t4(increment);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    cout << "Counter = " << counter << endl;

    return 0;
}