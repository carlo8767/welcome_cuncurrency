#include <iostream>
#include <thread>
#include <semaphore>
#include <chrono>
#include <vector>

const int ticketNumbers = 5;
//const int ticketNumbersLeastMaxValue = ticketNumbers+1;
const int buyerNumbers = 10;

std::counting_semaphore<ticketNumbers> ticketVendor(ticketNumbers);

void buyTicket(){
    // Fresh, thread independent randomness
    srand(time(0));
    std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 1000)); 

    ticketVendor.acquire();
    std::cout << "Booked ticket. \n";
    // << std::endl;
}


int main(){
    std::vector<std::thread> ticketBuyers(buyerNumbers);

    //Create many buyers
    for (int i=0; i< buyerNumbers; i++){
        ticketBuyers[i] = std::thread(buyTicket);
    } 
    //Wait until all buyers are dealt with
    for (auto &thread: ticketBuyers) thread.join();
}