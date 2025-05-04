#include <iostream>
#include <optional>

std::optional<int> integerDivision(int  numerator, int denominator){
    if(denominator==0){
        return {std::nullopt};
    }

    return numerator/denominator;
}

/*is a class template type that implements an optional value. That is, a 
* std::optional<T> can either have a value of type T, or not.
*/

int main(){
    std::optional<int> optResult1{integerDivision(4,2)};

    if(optResult1){
        std::cout<<"optResult1 = "<<*optResult1<<"\n";
    }
    else{
        std::cout<<"optResult1 failed."<<"\n";
    }

    //You can initialize an std::optional with no value.
    std::optional<int> optResult2{};
    std::optional<int> optResult3{std::nullopt};

    std::cout<<"optResult2 has value "<<*optResult2<<"\n";
    std::cout<<"optResult3 has value "<<*optResult2<<"\n";

    //To see if a std::optional has a value, we can choose one of the following.
    //WARNING: Dereferencing without a value causes undefined behavior.
    if(optResult1.has_value()){
        std::cout<<"optResult has value "<<*optResult1<<"\n";
    }
    
    // use implicit conversion to bool to check if o2 has a value
    if(optResult1){
        std::cout<<"optResult has value "<<*optResult1<<"\n";
    }


    /*Semantically, a pointer and a std::optional are quite different. A std::optional 
    * has value semantics, meaning it actually contains its value, and assignment copies 
    * the value. If we return a std::optional by value, the std::optional (including the
    * contained value) is copied back to the caller. This means we can return a value 
    * from the function back to the caller using std::optional*/

    /*Best practice: Return a std::optional (instead of a sentinel value) for functions 
    that may fail, unless your function needs to return additional information about why 
    it failed.
    */

    /*Because std::optional makes a copy of its argument, this becomes problematic when 
    * T is an expensive-to-copy type (like std::string) as currently std::optional does not 
    * support references. Therefore, we recommend using std::optional<T> as an optional 
    * parameter only when T would normally be passed by value. Otherwise, use const T*.
    */

    /*Best practice: Prefer std::optional for optional return types.
    * Prefer function overloading for optional function parameters (when possible). Otherwise, use 
    * std::optional<T> for optional arguments when T would normally be passed by value. Favor 
    * const T* when T is expensive to copy.*/

    return 0;
}