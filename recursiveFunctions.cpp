#include <iostream>

// A recursive function in C++ is a function that calls itself.
constexpr int sumCountDown(const int input){
    //Base case to break recursion.
    if(input<=0){
        return 0;
    }
    
    //Base case to break recursion.
    if(input==1){
        return 1;
    }

    /* We recurse with value input - 1 rather than --input. We do this because operator--  
       has a side effect, and using a variable that has a side effect applied more than
       once in a given expression will result in undefined behavior.
    */
    return input + sumCountDown(input-1);
}

int main(){
    /* In general, recursion is a good choice when most of the following are true:
       1. The recursive code is much simpler to implement.
       2. The recursion depth can be limited (e.g. there’s no way to provide an input 
          that will cause it to recurse down 100,000 levels).
       3. The iterative version of the algorithm requires managing a stack of data.
       4. This isn’t a performance-critical section of code.
    */
    std::cout<<sumCountDown(10)<<"\n";

    return 0;
}