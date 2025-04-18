//A constexpr function is a function that is allowed to be called in a constant expression.
template<typename T>
constexpr T square(T base){
    return base*base;
}

int main(){
    //The two following statements will be determined as compile time.
    constexpr auto base{2};
    [[maybe_unused]] constexpr auto baseSquared{square(base)};

    /*constexpr functions can also be called at runtime. When a constexpr 
    * function evaluates at runtime, it evaluates just like a normal 
    * (non-constexpr) function would.
    */
    auto myDouble{3};
    [[maybe_unused]] auto myDoubleSquared{square(myDouble)};

    return 0;
}