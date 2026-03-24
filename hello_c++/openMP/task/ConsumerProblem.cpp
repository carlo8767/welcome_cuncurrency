#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>

using namespace std;
vector <int> v1;
mutex mtx;
std::counting_semaphore <20> s1 (0);
bool finished = false;

void producer()
{
    for (int i = 1; i <= 20; i++)
    {   
        v1.push_back(i);
        s1.release();
    }
    
}

void consumer(int id)
{
        v1.erase(v1.begin() + id);
        s1.acquire();
 
}

int main()
{
    thread p(producer);

    thread c1(consumer, 1);
    thread c2(consumer, 2);

    p.join();
    c1.join();
    c2.join();

    return 0;
}