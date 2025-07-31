#include <iostream>
#include <utility>
#include <string>

template<typename T>
void swapValues(T& val1, T& val2){
    T temp{std::move(val1)}; //invokes move constructor
    val1=std::move(val2); //invokes move assignment
    val2=std::move(temp); //invokes move assignment
}

int main(){
    std::string myString1{"Hello"};
    std::string myString2{"World"};

    /*std::move is a standard library function that casts (using static_cast) its argument
      into an r-value reference, so that move semantics can be invoked. Thus, we can use 
      std::move to cast an l-value into a type that will prefer being moved over being 
      copied use as std::string, std::vector or other costly to copy objects.
    */

    /*Note: Moved from objects will be in a valid, but possibly indeterminate state the C++ 
      standard says, “Unless otherwise specified, moved-from objects [of types defined in the 
      C++ standard library] shall be placed in a valid but unspecified state.”
    */

    std::cout << "myString1 = " << myString1 << "\nmyString2 = " << myString2<<"\n"; 
    
    swapValues(myString1, myString2);

    std::cout << "myString1 = " << myString1 << "\nmyString2 = " << myString2<<"\n"; 
    
    return 0;
}