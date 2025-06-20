#include <iostream>
#include <array>

/*The non type parameter must be size_t not int because std::array is
  defined as template<class T, std::size_t N> struct array;. If you use
  int as the type of the non-type template parameter, the compiler will
  be unable to match the argument of type std::array<T, std::size_t>
  with the parameter of type std::array<T, int> (and templates won’t do
  conversions).
*/
template<typename T, std::size_t arrSize>
void printArrayElements(const std::array<T,arrSize> arr){
    static_assert(arrSize>0,"Array is empty");

    //Instead of static_assert as a compile time check you can
    //also use std::get()

    //gets value at arr[1]
    std::cout<<std::get<1>(arr)<<"\n";

    for(const T&element:arr){
        std::cout<<element<<"\n";
    }
}

//From c++20 and beyond you can use auto for the non template type.
template<typename T, auto arrSize>
void printArrayElementsV2(){
    //Function for example only.
}

int main(){
    //Remember: If not using constexpr array consider using vector.
    constexpr std::array myArray{1,2,3};

    printArrayElements(myArray);
    return 0;
}