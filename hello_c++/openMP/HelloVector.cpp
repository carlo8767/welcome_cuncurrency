
#include <vector>
#include <string>



class HelloVector {

    std:: vector<int> v1;
    
    HelloVector(std:: vector<int> newVector){
        v1 = newVector;
    }
    

    public : 
    void generateCar (){
        std:: vector<std::string> vectorCar = {"Ferrari", "Porshce"};
        vectorCar.push_back("Meclaren");
        vectorCar.at(0) = "Toyota";
    }

};


