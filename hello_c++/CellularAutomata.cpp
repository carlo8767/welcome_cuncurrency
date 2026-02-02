#include <array>
#include <vector>
#include <map>
#include<iostream>
#include <string>
#include <bitset>
using namespace

// https://www.geeksforgeeks.org/cpp/containers-cpp-stl/
//  8-bit binary number.

class CellularAutomata {
    public: std::array<std::string,16> ruleset;
    std::map<std::string, std::string> mapRuleset;
    std::map<int, std::string> mapRulesetBinary;
    
    CellularAutomata (){
        /// There are 256 possible combinations amd you begin from the center
        ruleset = {"0", "0", "0", "0", "0", "0", "0", "1", "0", "0", "0", "0", "0", "0", "0", "0"};
        mapRuleset = {{"010","2"}};
    }
    void updateFunctionRule( std::array<std::string,8> &arrays){
        int mid = arrays.size() / 2;
        std::string extract_values = arrays[mid-1]+arrays[mid]+arrays[mid+1];
        std::string value = mapRuleset[extract_values];
        if(!value.empty()){
            arrays[mid -1] = value[0];
            arrays[mid]= value[1];
            arrays[mid+1] = value[2];
        }
    }


    void combinationsRuleSet(){
        // CREATE THE BINARY RULESET
        for(int i=0; i<257;i++){
            std::bitset<9> binary(i);
            std::string n = binary.to_string();
            this->mapRulesetBinary.insert({i,n});
        }
    }


    // ADD RECURSION!!
    void celarrAutomataDecode(){
         std::map<std::string, std::string> mapping = {{"111","7"},{"110","6"},{"101","5"},{"100","4"},{"011","3"},{"010","2"},{"001","1"},{"000","0"}};
        // 30
        string map = "00011110";
        std::string concat = "";
        std::map<int, std::string> time;
        std::array<std::string,8> chainValues  = { "0", "0", "0", "1","0","0","0","0"};
        std::array<std::string,8> updateChainValues  = { "0", "0", "0", "1","0","0","0","0"};
        int mid = chainValues.size()/2-1;
        int s = chainValues.size()/2-1;

        // CENTER TO LEFT
        for(int i=3; i> 2;i--){
                std::string extract_values = chainValues[(i-1)]+chainValues[i]+chainValues[(i+1)];
                int index = stoi(mapping[extract_values]);
                updateChainValues[i] = map[index];
        }
        //  CENTRE TO RIGHT
         for(int s= 3; s<chainValues.size()-2;s++){
                std::string extract_values = chainValues[s-1]+chainValues[s]+chainValues[s+1];
                int index = stoi(mapping[extract_values]);
                updateChainValues[s] = map[index];
        }

        for(int i=0; i<updateChainValues.size();i++){
            std::cout << updateChainValues[i] << "\n";
        }

    }


    void printResultCombination(std::array<std::string,8> arrays, int ruleset){
            // EXTRACT RULESET
            std::cout << this->mapRulesetBinary[ruleset] << std::endl;

            std::string rulesetMap = mapRulesetBinary[ruleset];
            int mid = arrays.size() / 2;
            // CENTER TO LEFT
            for(int i=mid; i>0;i--){
                std::string extract_values = arrays[mid-1]+arrays[mid]+arrays[mid+1];
                std::string value = mapRuleset[extract_values];
                if(!value.empty()){
                arrays[mid-1] = value[0];
                arrays[mid]= value[1];
                arrays[mid+1] = value[2];
            }
            }

              // CENTER TO LEFT
            for(int i=mid; i<arrays.size();i++){
                std::string extract_values = arrays[mid-1]+arrays[mid]+arrays[mid+1];
                std::string value = mapRuleset[extract_values];
                if(!value.empty()){
                arrays[mid-1] = value[0];
                arrays[mid]= value[1];
                arrays[mid+1] = value[2];
            }
            }

    }
};

int main() {

CellularAutomata cellars = CellularAutomata();
std::array<std::string,8> chainValues  = { "0", "0", "0", "1","0","0","0","0"};
cellars.updateFunctionRule(chainValues);
cellars.combinationsRuleSet();
cellars.celarrAutomataDecode();

}