#include <iostream>
#include <thread>
#include <semaphore>
#include <chrono>
#include <mutex>

// Can I just replace binary_semaphore here by mutex? Justify your answer.


/*
I can replace binary with mutex because I can only one time read and only one time writing
*/
std::binary_semaphore wr(1);
std::mutex rd; //Or binary semaphore
int numReaders = 0;

std::mutex bufferAccess;

int buffer[6] = {0,0,0,0,0,0};

void printBuffer(){
    std::string bufferString = "";
    for (int i = 0; i < 6; i++){
        bufferString +=  std::to_string(buffer[i]);
        if (i != 5) bufferString += ",";
    }
    std::cout << bufferString << std::endl;
}

void writing(){
    srand(time(0));
    while (true){
        wr.acquire();
        int index = rand()%6;
        buffer[index] = rand() % 100 + 1;
        std::cout << "Writing " << buffer[index] << " to index " << index << std::endl;
        wr.release();
        std::this_thread::sleep_for(std::chrono::seconds(rand() % 10)); 
    }

}

void reading(){
    srand(time(0));
    while (true){
        // Must both lines (increment and if) be between lock() and unlock()?
        rd.lock();
        std::thread::id this_id = std::this_thread::get_id();
        std::cout << "Waiting for release " <<  this_id <<"\n";
        numReaders++;
        std::cout <<  "numReaders " <<  numReaders <<"\n";
        if (numReaders==1) wr.acquire(); 
        std::cout << "acquire " << this_id  << "\n";;
        rd.unlock(); 

        int index = rand()%6;
        std::cout << "Reading " << this_id << " " << buffer[index] << " from index " << index << std::endl;

        // Must both lines (decrement and if) be between lock() and unlock()?
        rd.lock();
        numReaders--; 
        // I do not need to bee the same 
        if (numReaders==0) {
            wr.release();
            std::cout << "Release is not the same " << this_id << " " << buffer[index] << " from index " << index << std::endl;
        };
            
        rd.unlock();

        std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); 
    }
}


int main(){
    /*
    std::thread writer(writing);
    std::thread reader(reading);
    writer.join();
    reader.join();
    */

    std::thread writer(writing);
    std::thread writer2(writing);
    std::thread writer3(writing);
    std::thread reader(reading);
    std::thread reader2(reading);
    std::thread reader3(reading);
    std::thread reader4(reading);
    writer.join();
    writer2.join();
    writer3.join();
    reader.join();
    reader2.join();
    reader3.join();
    reader4.join();
    
}