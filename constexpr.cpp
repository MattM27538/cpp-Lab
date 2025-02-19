#include <iostream>

int main(){

    //Constexpr are determined at compile time. 
    //Useful for predictability, quality/performance(both check for errors and evaluate at compile time.)
    constexpr int One={1};

    std::cout << "hello world"; // This can be determined at runtime or compile time depending on compiler.

    const int a={5}; // Can be used in a const expression.

    //Test
    constexpr int test=a;

    std::cout << "\n" << a << "\n";

    int b={5}; // Cannot be used in const expression because b is not const(might not be determined at compile time).

    // Uncomment to test for compile time error.
    // constexpr int test2=b;
    
    // Also cannot be used in const expression
    const int e {b};
    
    // Uncomment to test for compile time error.
    // constexpr int test3=e;


    // This is not necessarily determined at compile time. Determination is only required in contexts that require a constant expression.
    int y {3+4}; 

    const int x {3+4}; // constant expression 3 + 4 must be evaluated at compile-time.
    return 0;
}