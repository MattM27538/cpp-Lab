#include <iostream>

//Global const and constexpr vars have internal linkage by default.
constexpr int g_MyInt={6};

// Static keyword makes function internally linked preventing it from being called from another other translational unit.
static int add(const int myInt, const int myInt2){
    return myInt+myInt2;
}

int main(){
    constexpr int myInt={2};
    constexpr int myInt2={2};
    std::cout<<add(myInt,myInt2);

    return 0;
}