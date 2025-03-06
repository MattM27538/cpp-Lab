#include <iostream>

int add(int myInt1, int myInt2);

/*  This extern variable is a forward declaration of a variable named g_myInt that is defined in
    "extern2.cpp". Compile them together to show that extern gives this translational unit access
    to the value of g_myInt in "extern2.cpp" via the line ' std::cout<<"g_myInt= "<<g_myInt<<"\n" '; below. */
extern const int g_myInt; 

/*  constexpr cannot be used in conjunction with the extern keyword. This is because the compiler needs to 
    know the value of the constexpr variable (at compile time). If that value is defined in some other file, 
    the compiler has no visibility on what value was defined in that other file. */

// This would not compile as constexpr variables can't be forward declared due to compiler lacking 
// visibility of it's value from other file:

// extern constexpr int g_myInt2;

int main(){

    constexpr int myInt={2};
    constexpr int myInt2={3};
    
    //This function is defined in "extern2.cpp. Compile them together to prove function default external linkage."
    std::cout<<"The add function produces: "<<add(myInt,myInt2)<<"\n";

    std::cout<<"g_myInt= "<<g_myInt<<"\n";

    return 0;
}