#include <chrono>
#include <iostream>
#include <thread>
#include <utility>
#include <string>



class ThreadHello {

    private: int number;

    ThreadHello(int number){
        // Arrow operator
        this->number = number;

    }

    void helloLoop(){
        std::string pippo = "String";
        for(int i=0; i<5; i++){
            std:: cout  << i << "pippo";
            /// << is the "stream insertion operator" and >> is the stream extraction operator.
            //They are meant repesent the direction the data is flowing. 
            // Into the stream, or out of the stream. 
            // Since "we" read from left to right, that allows for chaning.
        }
    }

    int getNumber(){
        return this->number;
    }

     int main () {
        ThreadHello t1 = ThreadHello(2);

 }

};


