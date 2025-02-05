#include <iostream>
#include "kidInitializerList.h"

using std::cout;
using std::endl;

int main(){

    kid kid1("Kyle",8,54,100);
    cout << kid1.getName() << endl;
    // "+" promotes any integer type with rank less or equal to rank of int or of a bit-field of type 
    // _Bool(until C23)bool(since C23), int, signed int, unsigned int to the value of type int.
    cout << "age: " << +kid1.getAge() << endl;
    cout << "height: " << +kid1.getHeightInches() << endl;
    cout << "weight: " << +kid1.getWeightLbs() << endl;
    return 0;
}