#include <iostream>
#include <typeinfo>

//The auto return type deduces the return type. This should only be used if 
//The return type is unimportant, difficult to express, or fragile.
auto sum(double myDouble, int myInt){
    // auto deduces return type to be double.
    std::cout<<"Return type of sum() is: "<<typeid(myDouble+myInt).name()<<"\n";
    return myDouble+myInt;
}

// Trailing return type
auto divide(int myInt, int myInt2)->float{
    return myInt+myInt2;
}

//Type deduction can’t be used for function parameter types. The following would not 
//compile pre c++20. c++20 uses function templates to allow this to compile and handle 
//such cases.
// void addAndPrint(auto x, auto y)

int main(){
    constexpr auto myInt{2};
    constexpr auto myInt2{3};
    constexpr auto myDouble{1.5};

    sum(myDouble,myInt);
    
    std::cout<<"Return type of divide() is: "<<typeid(divide(myInt, myInt2)).name()<<"\n";

    return 0;
}