#include <iostream>

int main(){
    constexpr int myInt={2};

    constexpr bool myBool=false;

    /*This conditional will be evaluated at compile time due to the constexp modifier. 
      Since the conditional evaluates to true the entire if-else block will be replaced
      with the true statement block.
    */
    if constexpr (myInt==2){
        std::cout<<"Conditional statement evaluated as true.\n";
    } 
    else{
        std::cout<<"Conditional statement evaluated as false.\n";
    }

    /*Since the conditional evaluates to true the entire if-else block will be replaced
      with the false statement block.
    */
    if constexpr (myBool){
        std::cout<<"Second conditional statement evaluated as true.\n";
    } 
    else{
        std::cout<<"Second conditional statement evaluated as false.\n";
    }

    return 0;
}