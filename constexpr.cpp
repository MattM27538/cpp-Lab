#include <iostream>

int main(){

    //Constexpr are determined at compile time. 
    //Useful for predictability, quality/performance(both check for errors and evaluate at compile time.)
    constexpr int myInt1={1};

    std::cout << "hello world"; // This can be determined at runtime or compile time depending on compiler.

    const int myInt2={5}; // Can be used in a const expression.

    //Test
    constexpr int myInt3={myInt2};

    std::cout << "\n" << myInt3 << "\n";

    int myInt4={5}; // Cannot be used in const expression because b is not const(might not be determined at compile time).

    // Uncomment to test for compile time error.
    // constexpr int myTestInt=myInt4;
    
    // Also cannot be used in const expression
    const int myInt5=myInt4;
    
    // Uncomment to test for compile time error.
    // constexpr int myTestInt2=myInt5;


    // This is not necessarily determined at compile time. Determination is only required in contexts that require a constant expression.
    int y {3+4}; 

    const int x {3+4}; // constant expression 3 + 4 must be evaluated at compile-time.
    return 0;
}