#include <iostream>
#include <cstdint>
#include <typeinfo>

/*An enumeration (also called an enumerated type or an enum) is a compound data type
* whose values are restricted to a set of named symbolic constants (called enumerators).
*/

//Enumerated types are best used when you have a smallish set of related constants, 
//and objects only need to hold one of those values at a time.

//Note: Unscoped enumerations have the same scope as the enumeration definition
//and should be kept inside namespaces so as not to pollute the global namespace.

namespace CarAttributes{
    enum Color{
        // Here are the enumerators
        // These symbolic constants define all the possible values this type can hold
        // Each enumerator is separated by a comma, not a semicolon
        unknown=0,
        red,
        blue,
        green=5, // trailing comma optional but recommended

        /*Best practice: Make the enumerator representing 0 the one that is the best 
        * default meaning for your enumeration. If no good default meaning exists, consider
        * adding an “invalid” or “unknown” enumerator that has value 0, so that state is 
        * explicitly documented and can be explicitly handled where appropriate.
        */
    };

    //Best practice: Specify the base type of an enumeration only when necessary.
    enum Price : std::int32_t{
        baseModel=25000,
        intermediateModel=28000,
    };
}



int main(){
    CarAttributes::Color carColor{CarAttributes::blue};
    CarAttributes::Color carColor2{CarAttributes::green};

    //enums implicitly convert to an integral type. Each enumerator starts at 0 and
    //increased by 1 unless otherwise assigned.
    std::cout<<"carColor{blue} prints as "<<carColor<<"\n";
    std::cout<<"carColor2{green} prints as "<<carColor2<<"\n";

    CarAttributes::Price baseModelPrice{CarAttributes::baseModel};

    std::cout<<"carPrice of baseModel = "<<baseModelPrice<<"\n";
    std::cout<<"Type of baseModelPrice = "<<typeid(CarAttributes::Price).name()<<"\n";

    return 0;
}