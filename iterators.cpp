#include <iostream>
#include <array>

int main(){
    //All standard library containers offer direct support for iteration.
    constexpr std::array myArray{0,1,2,3};
    [[maybe_unused]] auto begin{myArray.begin()};
    [[maybe_unused]] auto end{myArray.end()};
    
    //A const_iterator is an iterator that points to const content.
    [[maybe_unused]] auto cbegin{myArray.cbegin()};
    [[maybe_unused]] auto cend{myArray.cend()};

    std::cout<<"myArray elements are ";

    /*Iterate through myArray using iterators. With iterators, it is 
      conventional to use operator!= to test whether the iterator has 
      reached the end element.This is because some iterator types are 
      not relationally comparable. operator!= works with all iterator types.
    */
    for(auto it{myArray.cbegin()};it!=myArray.cend();++it){
        std::cout<<*it<<" ";
    }
    
}