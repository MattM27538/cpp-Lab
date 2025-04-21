#include <iostream>

//the keyword consteval is used to indicate that a function must evaluate at compile-time.
consteval int square(int base){
    if(std::is_constant_evaluated()){
        return base*base;
    }

    return 0;
}

int main(){
    constexpr auto base{2};

    constexpr auto squaredBase{square(base)};

    //Note how squaredBase evaluates to 4 because std::is_constant_evaluated() is
    //true because the square() function call is evaluated at compile time.
    std::cout<<"squaredBase = "<<squaredBase<<"\n";
    
    /*You can force something to be evaluated at runtime using consteval. Normally
    * squareAtRuntime could be evaluated at runtime but because it is initialized
    * using a consteval function squareAtRuntime evaluates at compile time.
    */
    auto squareAtRuntime{square(3)};
    std::cout<<"squaredAtRuntime = "<<squareAtRuntime<<"\n";
    
    [[maybe_unused]] constexpr auto squaredLiteral{square(3)};

    return 0;
}