#include <iostream>
#include <cstdlib>

void printNumber(const int& number){
    std::cout<<"Called printNumber(int& number). Number is "<<number<<"\n";
}


void printNumber(int&& number){
    std::cout<<"Called printNumber(int&& number). Number is "<<number<<"\n";
}

int main(){
    /*An r-value reference is a reference that is designed to be initialized with an r-value (only).
      R-value references have two properties that are useful. First, r-value references extend the
      lifespan of the object they are initialized with to the lifespan of the r-value reference 
      (l-value references to const objects can do this too). Second, non-const r-value references 
      allow you to modify the r-value!
    */
    int&& myIntRRef{2};

    constexpr int myInt{3};

    const int& myIntLRef{myInt};

    /*most useful for function overloads when you want to have different behavior for l-value
      and r-value arguments.  
    */
    printNumber(5); //call with rvalue reference.
    
    printNumber(myIntLRef); //call with lvalue reference.
    
    //Although variable myIntRRef has type int&&, when used in an expression it is an lvalue 
    //(as are all named variables).
    printNumber(myIntRRef); //call with lvalue reference.

    return EXIT_SUCCESS;
}