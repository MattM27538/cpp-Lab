#include <iostream>
#include <cstdlib>

int main(){
    /*A lambda expression (also called a lambda or closure) allows us to define an anonymous
      function inside another function. The nesting is important, as it allows us both to
      avoid namespace naming pollution, and to define the function as close to where it is
      used as possible (providing additional context).
    */

    constexpr int captureNumber{7};

    /*Named lamba. Brackets capture variables from parent scope and makes a clone of that 
      variable. When the compiler encounters a lambda definition, it creates a custom object 
      definition for the lambda. Each captured variable becomes a data member of the object.
      When a lambda is called, operator() is invoked. By default, this operator() treats 
      captures as const. Capture by reference should be preferred over capture by value 
      whenever you would normally prefer passing an argument to a function by reference.
    */

    auto printCapturedVariable{
        [captureNumber]()->void{
            std::cout << "Captured number is " << captureNumber << "\n";
        }
    };

    printCapturedVariable();

    auto isFirstDigitGreater{
        [captureNumber](int firstDigit, int secondDigit)->bool{
            return firstDigit>secondDigit;
        }
    };

    /*Best practice Following the best practice of defining things in the smallest scope and
      closest to first use, lambdas are preferred over normal functions when we need a
      trivial, one-off function to pass as an argument to some other function.
    */

    std::cout << "1>2 = " << std::boolalpha << isFirstDigitGreater(1,2) << "\n";

    /*(C++20)Because lambdas with one or more auto parameter can potentially work with a wide
      variety of types, they are called generic lambdas.
    */
    auto isGreaterThan{
        [](auto firstValue, auto secondValue){
            return firstValue>secondValue? true:false;
        }
    };
   
    std::cout << "Is 3 greater than 5 = " << std::boolalpha << isGreaterThan(3,5) << "\n";

    return EXIT_SUCCESS;
}