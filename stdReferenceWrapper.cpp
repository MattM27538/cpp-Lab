#include <iostream>
#include <functional>
#include <cstdlib>
#include <array>

int main(){
    int myInt{5};
    constexpr int myInt2{3};
    int myInt3{4};
    //std::reference_wrapper takes a type template argument T, and then behaves like 
    //a modifiable lvalue reference to T. 
    
    //c++17 and on you can use CTAD.
    std::reference_wrapper<int> myRefWrapper{myInt};

    /*Other ways to declare reference wrapper used std::ref and std::cref. The std::ref() 
      and std::cref() functions were provided as shortcuts to create std::reference_wrapper 
      and const std::reference_wrapper wrapped objects. Note that these functions can be used
      with auto to avoid having to explicitly specify the template argument.
    */

    auto myRefWrapper2{std::cref(myInt2)};
    //or
    int myRefWrapper3{std::cref(myInt3)};

    /*std::reference_wrapper is useful when you need to store or pass references to objects 
    in contexts where direct references are not allowed or convenient, such as within 
    containers or when working with functions that take objects by value.
    */

    std::array<std::reference_wrapper<int>,2> myArray{myInt,myInt3};
    
    /*Note that we must use  myRefWrapper.get()=4; and not myRefWrapper=4; .The latter
      is ambiguous, as the compiler can’t tell if we intend to reseat the 
      std::reference_wrapper<int> to value 5 (something that is illegal anyway) or 
      change the value being referenced. Using get() disambiguates this.
    */

    myRefWrapper.get()=4;

    /*std::reference_wrapper<T> will implicitly convert to T&. When printing myArray[1], the 
      compiler will realize it can’t print a std::reference_wrapper<int>, so it will implicitly
      convert it to an int&, which it can print. So we don’t need to use get() here.
    */
    std::cout<<"myRefWrapper = "<<myRefWrapper<<'\n';  
    
    return EXIT_SUCCESS;
}