#include <array>
#include<iostream>

// https://www.geeksforgeeks.org/cpp/containers-cpp-stl/
class CellularAutomata {

    private: std::array<int,8> ruleset;
    


    CellularAutomata (){
        this->ruleset = {111, 011, 101, 100, 011, 010, 001, 000};
    }
    



};