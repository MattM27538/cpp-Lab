#ifndef kid_h
#define kid_h
#include <cstdint>
#include <string>

using std::string;

class kid {
    private:
        string name;
        int8_t age;
        int8_t heightInches;
        int16_t weightLbs;

//Example initializer list
    public:
        //Default constructor
        kid(): name(""),age{NULL},heightInches{NULL},weightLbs{NULL} {std::cout<<"did default";}

        //specific constructor
        kid(string name, int8_t age, int8_t heightInches, int16_t weightLbs): name(name),age{age},heightInches{heightInches},weightLbs{weightLbs} {}
        
        //Member getters
        string getName(){
            return name;
        }

        int getAge(){
            return age;
        }

        int8_t getHeightInches(){
            return heightInches;
        }

        int8_t getWeightLbs(){
            return weightLbs;
        }
};


#endif