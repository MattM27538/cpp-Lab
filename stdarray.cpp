#include <array>

int main(){
    //std::array is an aggregate and so is initialized using agggregate initialization.
    [[maybe_unused]] constexpr std::array<int,3> myArray{1,2,3};

    /*Even though the elements of a const std::array are not explicitly marked as const, 
    they are still treated as const (because the whole array is const).
    */
    [[maybe_unused]] const int* myConstPtr=&myArray.data()[0];

    // int* myIntPtr=&myArray.data()[0]; would cause compilation error.

    /*Best practice: Define your std::array as constexpr whenever possible. If your 
      std::array is not constexpr, consider using a std::vector instead.
    */

    /*Best practice: Use class template argument deduction (CTAD) to have the compiler
     deduce the type and length of a std::array from its initializers.
    */
    //Type deduced to be double.
    [[maybe_unused]] constexpr std::array myArray2{2.0,3.0,4.0};

    /*CTAD does not support partial omission of template arguments (as of C++23), so 
      there is no way to use a core language feature to omit just the length or just the 
      type of a std::array
      constexpr std::array<int> a2 { 9, 7, 5, 3, 1 }; // error: too few template arguments (length missing)
    */


    /*Using std::to_array is more expensive than creating a std::array directly, because 
      it involves creation of a temporary std::array that is then used to copy initialize 
      our desired std::array. For this reason, std::to_array should only be used in cases 
      where the type can’t be effectively determined from the initializers, and should be 
      avoided when an array is created many times (e.g. inside a loop).
    */
    [[maybe_unused]] constexpr auto stdShortArray{std::to_array<short>({0,1,2})};
    
    return 0;
}