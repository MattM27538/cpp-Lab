#include <iostream>
#include <algorithm> //for std::copy

int main(){
    /*1. The length of the array must be a constant expression (of type std::size_t, though this 
         typically doesn’t matter).
      2. C-style arrays will accept signed or unsigned indexes (or unscoped enumerations).
      3. Just like std::array, C-style arrays are aggregates, which means they can be initialized 
         using aggregate initialization.
      4. Best practice: Prefer omitting the length of a C-style array when explicitly 
         initializing every array element with a value.
    */

    constexpr int myArray[]{0,1,2,3,4}; //deduced by compiler to have length 5.

    //Get the size of the array with sizeof(). From c++17 onward we can use std::size and std::ssize.
    std::cout<<"The size of myArray is "<<sizeof(myArray)<<"\n";

    //note: There is no overhead here. An C-style array object contains its elements and nothing more.
    
    int myArray2[]{5,6,7,8,9};
    int myArray3[]{1,2,3,4,5};

    /*C++ arrays don’t support assignment but you can assign new values to a C-style array 
      element-by-element, or use std::copy to copy an existing C-style array.
    */
    
    std::copy(std::begin(myArray2),std::end(myArray2),std::begin(myArray3));

    std::cout<<"The elements of myArray3 are ";
    for(const auto& element:myArray3){
        std::cout<<element<<" ";
    }

    std::cout<<"\n";

    return 0;
}