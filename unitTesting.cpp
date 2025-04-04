#include <iostream>

int squareNumPlusFive(int num){
    return (num*num)+5;
}

/*
Testing a small part of your code in isolation to ensure that “unit” of 
code is correct is called unit testing. 
Each unit test is designed to ensure that a particular behavior of the unit is correct.
*/
int testSquareNumPlusFive(int num){
    return squareNumPlusFive(num);
}

/*
For integers, make sure you’ve considered how your function handles negative values, 
zero, and positive values. You should also check for overflow if that’s relevant.
*/
int main(){
    constexpr int myInt={4};
    constexpr int myInt2={0};
    constexpr int myInt3={-4};
    constexpr int myInt4={2147483646};

    std::cout<<"Input = "<<myInt<<", output = "<<testSquareNumPlusFive(myInt)<<"\n";
    std::cout<<"Input = "<<myInt2<<", output = "<<testSquareNumPlusFive(myInt2)<<"\n";
    std::cout<<"Input = "<<myInt3<<", output = "<<testSquareNumPlusFive(myInt3)<<"\n";
    //Note how this function call creates an overflow and an incorrect answer. Input = 2147483647, output = 6
    std::cout<<"Input = "<<myInt4<<", output = "<<testSquareNumPlusFive(myInt4)<<"\n";

    return 0;
}